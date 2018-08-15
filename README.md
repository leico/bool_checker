
# bool_checker

provide and/or function between variadic template parameters

## functions

### `bool_checker :: ored< bool... Args > :: value`

`value` returned `Args1 || Args2 || Args3 ||...` 


### `bool_checker :: anded< bool... Args > :: value`

`value` returned `Args1 && Args2 && Args3 && ...`


### `bool_checker :: ored_t< Args... >:: value`

`value` returned `Args1 :: value || Args2 :: value || Args3 :: value || ...`

### `bool_checker :: anded_t< Args... >:: value`

`value` returned `Args1 :: value && Args2 :: value && Args3 :: value && ...`



## 簡単な解説

### ored

```cpp
template < bool... Args > 
  struct ored {
  ...
    public: 
      static constexpr bool value = impl< Args... > :: value;
  };
```
可変テンプレートパラメータを受け取り、実行用メタ関数 `impl` に渡している。
`value` は `impl` の返り値 `value` で定義している。

```cpp
template < bool... NoArgs > 
struct impl { 
  static constexpr bool value = false;
};
```

パラメータが何もない状態まで行ってしまったら `false` を返す。

```cpp
template < bool... Tail > 
struct impl< true, Tail... > { 
  static constexpr bool value = true;
};

template < bool... Tail > 
struct impl< false, Tail... > { 
  static constexpr bool value = impl< Tail... > :: value;
};
```

`true` が見つかった時点で `true` を返す。`false` の場合、先頭を削ってもうもう一度 `impl` を実行する。

### anded 

```cpp
template < bool... Args > 
struct anded { 
  private:

    template < bool... NoArgs > 
    struct impl { 
      static constexpr bool value = true;
    };
  ...

  public: 
    static constexpr bool value = sizeof...( Args ) == 0 ? false : impl< Args... > :: value; 
};
```

今度は最後まで行ったら `true` を返すようになっているが、
それだと引数が何もない状態でも `true` が返ってしまうので、
`sizeof...( Args ) == 0 ? false : impl< Args... > :: value `
と、 `Args` のサイズが `0` の場合は `false` が返るようにしている。

```cpp
template < bool... Tail > 
struct impl< false, Tail... > { 
  static constexpr bool value = false;
};

template < bool... Tail > 
struct impl< true, Tail... > { 
  static constexpr bool value = impl< Tail... > :: value; 
};
```

`true` であれば先頭を削ってもうもう一度 `impl` を実行、`false` であれば`false` を返す。

## example

```cpp
struct A : public std :: true_type  {  };
struct B : public std :: false_type {  };
struct C : public std :: true_type  {  }; 
struct D : public std :: false_type {  };

void print(const bool value){
  std :: cout << std :: boolalpha << value << std :: endl;
}
...

  print( bool_checker :: ored < > :: value ); //false
  print( bool_checker :: anded< > :: value ); //false

  print( bool_checker :: ored< false, false, false >       :: value ); //false
  print( bool_checker :: ored< false, false, false, true > :: value ); //true

  print( bool_checker :: anded< true, false, true, false, true > :: value ); //false
  print( bool_checker :: anded< true, true >                     :: value ); //true

  print( bool_checker :: ored_t< B, C, D >                 :: value ); //true
  print( bool_checker :: ored_t< B, D, std :: false_type > :: value ); //false

  print( bool_checker :: anded_t< A, C, std :: true_type > :: value ); //true
  print( bool_checker :: anded_t< A, B, C, D >             :: value ); //false

  //true
  print( 
    bool_checker :: anded_t< 
        bool_checker :: ored_t< A, B >
      , bool_checker :: ored_t< C, D >
    > :: value ); 
```

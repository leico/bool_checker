
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

パラメータが何もない場合は `false` を返す。
 
## example



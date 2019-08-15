//
//  main.cpp
//
//
// MIT License
// 
// Copyright (c) 2018 leico
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include <iostream>
#include <type_traits> 
#include "bool_checker.h" 

struct A : public std :: true_type  {  };
struct B : public std :: false_type {  };
struct C : public std :: true_type  {  }; 
struct D : public std :: false_type {  };

void print(const bool value){
  std :: cout << std :: boolalpha << value << std :: endl;
}

int main(int argc, const char * argv[]) {

  namespace bool_checker = leico_cpp_utility :: bool_checker;

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

  return 0;
}






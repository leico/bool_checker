//
//  bool_checker.h
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


#ifndef leico_cpp_utility_bool_checker_h
#define leico_cpp_utility_bool_checker_h

#include <utility> 

namespace leico_cpp_utility {
namespace bool_checker { 

  //ored returned true if bool parameters has a true, otherwise false
  template < bool... Args > 
  struct ored {

    private: 

      template < bool... NoArgs > 
      struct impl { 
        static constexpr bool value = false;
      };

      template < bool... Tail > 
      struct impl< true, Tail... > { 
        static constexpr bool value = true;
      };

      template < bool... Tail > 
      struct impl< false, Tail... > { 
        static constexpr bool value = impl< Tail... > :: value;
      };

    public: 
      static constexpr bool value = impl< Args... > :: value;
  };



  // ored_t returned true if Args :: value... has a true, othewise false
  template < typename... Args > 
  struct ored_t { 
    static constexpr bool value = ored< (Args :: value)... > :: value ;
  };


  //anded returned true if all bool parameters are true, othewise false, but sizeof...(Args) == 0 returned false
  template < bool... Args > 
  struct anded { 
    private:

      template < bool... NoArgs > 
      struct impl { 
        static constexpr bool value = true;
      };

      template < bool... Tail > 
      struct impl< false, Tail... > { 
        static constexpr bool value = false;
      };

      template < bool... Tail > 
      struct impl< true, Tail... > { 
        static constexpr bool value = impl< Tail... > :: value; 
      };

    public: 
    static constexpr bool value = sizeof...( Args ) == 0 ? false : impl< Args... > :: value; 
  };

  //anded_t returned true if Args :: value ... are true, otherwise false
  template < typename... Args > 
  struct anded_t {
    static constexpr bool value = anded< ( Args :: value )... > :: value; 
  };



}
}

#endif /* leico_cpp_utility_bool_checker_h */

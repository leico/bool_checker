//
//  has_member_function.h
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

#ifndef leico_cpp_utility_has_member_function_h
#define leico_cpp_utility_has_member_function_h


namespace leico_cpp_utility { 
namespace has_member_function { 

#define LEICO_CPP_UTILITY_HAS_MEMBER_FUNCTION( FunctionName, UniqueID, ... ) \
template < typename T > \
class FunctionName##UniqueID { \
\
  template< typename Arg > \
  static auto impl( ... ) -> std :: false_type; \
\
  template < typename Arg > \
  static auto impl( Arg* ) -> \
  decltype( \
      std :: declval < Arg >() . FunctionName( __VA_ARGS__ ) \
    , std :: true_type() \
  ); \
\
  public: \
    static constexpr bool value = decltype( impl< T >(nullptr) ) :: value ; \
};

LEICO_CPP_UTILITY_HAS_MEMBER_FUNCTION( size,,  ); // check is T.size()  exist
LEICO_CPP_UTILITY_HAS_MEMBER_FUNCTION( begin,, ); // check is T.begin() exist
LEICO_CPP_UTILITY_HAS_MEMBER_FUNCTION( end,,   ); // check is T.end()   exist
LEICO_CPP_UTILITY_HAS_MEMBER_FUNCTION( empty,, ); // check is T.empty() exist


}
}

#endif /* leico_cpp_utility_has_member_function_h */

//
//  has_member_type.h
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

#ifndef leico_cpp_utility_has_member_type_h
#define leico_cpp_utility_has_member_type_h

namespace leico_cpp_utility{
namespace has_member_type {

#define LEICO_CPP_UTILITY_HAS_MEMBER_TYPE( MemberType ) \
template < typename T > \
class MemberType { \
\
template < typename Arg > \
static std :: false_type impl( ... ); \
\
template < typename Arg > \
static std :: true_type impl( typename Arg :: MemberType* ); \
\
public: \
static constexpr bool value = decltype( impl< T >( nullptr ) ) :: value; \
};

LEICO_CPP_UTILITY_HAS_MEMBER_TYPE( value_type ); // generate has_member_type :: value_type< T > :: value;
LEICO_CPP_UTILITY_HAS_MEMBER_TYPE( iterator );   // generate has_member_type :: iterator  < T > :: value;
}
}

#endif /* leico_cpp_utility_has_member_type_h */

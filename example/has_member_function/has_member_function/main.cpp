//
//  main.cpp
//  has_member_function
//
//  Created by leico_studio on 2019/08/15.
//  Copyright © 2019 leico_studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include "has_member_function.h"

void print( const bool value ){ 
  std :: cout << std :: boolalpha << value << std :: endl;
}

struct A {  };
struct B {  };
struct C {  
  void fx ( const A&, const B& );
};

struct D{ 
  void fx( void );
};

struct E { 
  int fx;
};


namespace leico_cpp_utility{
namespace has_member_function{ 
  LEICO_CPP_UTILITY_HAS_MEMBER_FUNCTION( at,, 0 );
  LEICO_CPP_UTILITY_HAS_MEMBER_FUNCTION( fx, A_B, A(), B() );
  LEICO_CPP_UTILITY_HAS_MEMBER_FUNCTION( fx, void, );
}
}

int main( void ) {

  namespace has_member_function = leico_cpp_utility :: has_member_function; 

  print( has_member_function :: size < std :: vector< int > > :: value ); // true
  print( has_member_function :: begin< std :: vector< int > > :: value ); // true
  print( has_member_function :: end  < std :: vector< int > > :: value ); // true
  print( has_member_function :: empty< std :: vector< int > > :: value ); // true

  print( has_member_function :: at   < std :: vector< int > > :: value ); // true

  print( has_member_function :: fxA_B  < C > :: value ); // true
  print( has_member_function :: fxvoid < D > :: value ); // true
  print( has_member_function :: fxvoid < E > :: value ); // false, fx is variable
  
  return 0;
}

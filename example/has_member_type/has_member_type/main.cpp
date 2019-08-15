//
//  main.cpp
//  has_member_type
//
//  Created by leico_studio on 2019/08/15.
//  Copyright © 2019 leico_studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include "has_member_type.h" 

struct dummy{};

void print( const bool value ){ 
  std :: cout << std :: boolalpha << value << std :: endl;
}


int main(int argc, const char * argv[]) {

  namespace has_member_type = leico_cpp_utility :: has_member_type;

  print( has_member_type :: value_type< dummy                > :: value ); //false
  print( has_member_type :: value_type< std :: vector< int > > :: value ); //true

  print( has_member_type :: iterator< dummy               > :: value ); //false
  print( has_member_type :: iterator< std :: list< char > > :: value ); //true

  return 0;
}

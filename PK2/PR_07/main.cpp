/* 
 * File:   main.cpp
 * Author: Danny
 *
 * Created on 23. Februar 2015, 14:15
 */

#include <iostream>
#include <iomanip>
#include "Matrix.hpp"

using namespace std;

int main(int argc, char** argv) {
    Matrix<int> m(2);
    
    m.set(0,0,1);
    m.set(0,1,2);
    m.set(1,0,3);
    m.set(1,1,4);
   
    std::cout << m << "*" << std::endl << m << "=" << std::endl << m*m;
    
    return 0;
}


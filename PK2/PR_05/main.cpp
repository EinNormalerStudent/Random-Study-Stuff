/* 
 * File:   main.cpp
 * Author: Danny
 *
 * Created on 25. Februar 2015, 12:17
 */

#include <cstdlib>
#include <cstddef>
#include <iostream>
#include "LinkedList.hpp"


using namespace std;

/*
 * 
 */
void gebeAus(const char*);

int main(int argc, char** argv) {
    LinkedList Liste;
    Liste.append("1");
    Liste.append("2");
    Liste.append("3");
    Liste.append("4");
    Liste.append("5");
    
    Liste.insert("0", 1);
    Liste.remove(2);
    
    cout<< Liste.first()<<" < " << Liste.get(3) <<" | " <<endl;

    Liste.visit_all(&gebeAus);
    
    return 0;
}

void gebeAus(const char* text) {
    cout<<text<<endl;
}
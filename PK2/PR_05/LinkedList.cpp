/* 
 * File:   LinkedList.cpp
 * Author: Danny
 * 
 * Created on 25. Februar 2015, 12:19
 */

#include <iostream>
#include "LinkedList.hpp"

LinkedList::LinkedList() {
}

LinkedList::LinkedList(const LinkedList& orig) {
}

LinkedList::~LinkedList() {
}

int LinkedList::append(const char * text) {
    Node* currentNode = this->m_First;
    
    Node* nNode = new Node();
    
    nNode->setValue((char*)text);
    
    if (!currentNode) {
        this->m_First = nNode;
        return 0;
    }
    
    while ( currentNode->getSuccessor() ) {
        currentNode = currentNode->getSuccessor();
    }
    
    currentNode->setSuccessor(nNode);
    nNode->setPredecessor(currentNode);
}

int LinkedList::insert(const char * text, int position) {
    Node* currentNode = this->m_First;
    
    Node* insertNode = new Node;
    insertNode->setValue((char*) text);
    
    for(int i = 0; i < position; i++) {
        currentNode = currentNode->getSuccessor();
    }
    
    if (currentNode->getPredecessor()) {
        currentNode->getPredecessor()->setSuccessor(insertNode);
    } else {
        this->m_First = insertNode;
    }
    
    insertNode->setPredecessor(currentNode->getPredecessor());
    insertNode->setSuccessor(currentNode);
    currentNode->setPredecessor(insertNode);
}

int LinkedList::remove(int position) {
    Node* currentNode = this->m_First;
    
    for(int i = 0; i < position; i++) {
        currentNode = currentNode->getSuccessor();
    }
    
    currentNode->getPredecessor()->setSuccessor(currentNode->getSuccessor());
    currentNode->getSuccessor()->setPredecessor(currentNode->getPredecessor());
  
    delete currentNode;
}

const char* LinkedList::get(int position) {
    Node* currentNode = this->m_First;
    
    for(int i = 0; i < position; i++) {
        currentNode = currentNode->getSuccessor();
    }
    
    return (const char*)currentNode->getValue();
}


int LinkedList::index_of(const char* text) {
    Node* currentNode = this->m_First;
    
    int i = 0;
    
    do {
        if ( *(currentNode->getValue()) ==  *text) {
            return i;
        }
        currentNode = currentNode->getSuccessor();
        i++;
    } while ( currentNode->getSuccessor() );
    
    if ( *(currentNode->getValue()) ==  *text) {
        return i;
    }
    
    return -1;
}

const char* LinkedList::first() {
    return this->m_First->getValue();
}

const char* LinkedList::last() {
    Node* currentNode = this->m_First;
    
    if (!currentNode) {
        return "None";
    }
    
    while ( currentNode->getSuccessor() ) {
        currentNode = currentNode->getSuccessor();
    }
    
    return currentNode->getValue();
}

void LinkedList::visit_all(void(*work)(const char*)) {
    Node* currentNode = this->m_First;
    
    if (!currentNode) {
        return;
    }
    
    work(currentNode->getValue());
    while ( currentNode = currentNode->getSuccessor() ) {
        //Call
        work(currentNode->getValue());
    }
}   
/* 
 * File:   Node.cpp
 * Author: Danny
 * 
 * Created on 25. Februar 2015, 12:28
 */


#include "Node.hpp"

Node::Node() {
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

char* Node::getValue() {
    return this->m_Value;
}

Node* Node::getPredecessor() {
    return this->m_Predecessor;
}

Node* Node::getSuccessor() {
    return this->m_Successor;
}

void Node::setValue(char* nValue) {
    this->m_Value = nValue;
}

void Node::setPredecessor(Node* nPredecessor) {
    this->m_Predecessor = nPredecessor;
}

void Node::setSuccessor(Node* nSuccessor) {
    this->m_Successor = nSuccessor;
}
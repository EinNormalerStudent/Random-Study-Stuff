/* 
 * File:   Node.hpp
 * Author: Danny
 *
 * Created on 25. Februar 2015, 12:28
 */

#ifndef Node_H
#define	Node_H

class Node {
    private:
        char* m_Value;
        Node* m_Predecessor;
        Node* m_Successor;
    public:    
        Node();
        Node(const Node& orig);
        virtual ~Node();
        
        char* getValue();
        Node* getPredecessor();
        Node* getSuccessor();
        
        void setValue (char *);
        void setPredecessor(Node*);
        void setSuccessor(Node*);
};

#endif	/* Node_H */
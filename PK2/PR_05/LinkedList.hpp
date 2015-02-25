/* 
 * File:   LinkedList.hpp
 * Author: Danny
 *
 * Created on 25. Februar 2015, 12:18
 */

#include "Node.hpp"

#ifndef LinkedList_H
#define	LinkedList_H

class LinkedList {
    private:
        Node* m_First;
    public:
        LinkedList();
        LinkedList(const LinkedList& orig);
        virtual ~LinkedList();
        
        int append(const char *);
        int insert(const char *, int);
        int remove(int);
        const char* get(int);
        int index_of(const char*);
        const char* first();
        const char* last();
        void visit_all(void(*work)(const char*));
};

#endif	/* LinkedList_H */


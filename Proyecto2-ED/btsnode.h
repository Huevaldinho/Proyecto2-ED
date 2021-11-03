#ifndef BTSNODE_H
#define BTSNODE_H

#include "Estructuras.h"

template <typename E>
class BTSNode{

    public:
    E element;
    BSTNode<E> *left;
    BSTNode<E> *right;

    BSTNode(E element, BSTNode<E> *left = nullptr, BSTNode<E> *right = nullptr){
        this->element = element;
        this->left = left;
        this->right = right;
    }
    bool isLeaf(){
        return left == nullptr && right == nullptr;
    }

    int childrenCount(){
        return (left == nullptr? 0 : 1) + (right == nullptr? 0 : 1);
    }

    BSTNode<E>* getUniqueChild(){
        return left == nullptr? right : left;
    }
};

#endif // BTSNODE_H

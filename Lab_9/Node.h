#ifndef NODE_H
#define NODE_H

#include "NodeInterface.h"

class Node : public NodeInterface
{
public:
    
    //constructor
    Node(int data) : data(data), left_child(NULL), right_child(NULL) {};
    //destructor
    virtual ~Node() {};
    
    virtual int getData() {return data;};
    virtual Node* getLeftChild() { return left_child;};
    virtual Node* getRightChild() {return right_child;};
    virtual int getHeight();
    
    int getMaxHeight(Node* current);
    int getBalance();
    int max(int x, int y);
    
    int data;
    Node* left_child;
    Node* right_child;

};

#endif
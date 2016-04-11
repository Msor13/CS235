#ifndef AVL_H
#define AVL_H

#include "AVLInterface.h"
#include "Node.h"

class AVL : public AVLInterface
{
public:
    
    //constructor
    AVL() : root(NULL) {};
    //destructor
    virtual ~AVL() { clear(root);};
    
    virtual Node* getRootNode() {return root;};
    virtual bool add(int data);
    virtual bool remove (int data);
    
private:
    Node* root;
    bool add_recursive(int data, Node*& current);
    bool remove_recursive(int data, Node*& current);
    bool inorder_predecessor(Node*& n1, Node*& n2);
    void clear(Node*& node);
    void rotate_right(Node*& n);
    void rotate_left(Node*& n);
    bool find(int data, Node*& current);
    void balance(Node*& n);
};

#endif
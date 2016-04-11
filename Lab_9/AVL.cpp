#include "AVL.h"

bool AVL::add(int data)
{
    bool is_added = false;
    
    if (root == NULL)
    {
        root = new Node(data);
        is_added = true;
    }
    else if (!find(data, root))
    {
        add_recursive(data, root);
        is_added = true;
    }
    return is_added;
}






bool AVL::remove(int data)
{
    bool is_removed = false;
    
    is_removed = find(data, root) ? remove_recursive(data, root) : false;
    
    return is_removed;
}






bool AVL::add_recursive(int data, Node *&current)
{
    bool added = false;
    
    if(current == NULL)
    {
        current = new Node(data);
        added = true;
    }
    else
    {
        if( data < current -> data)
        {
            added = add_recursive(data, current->left_child);
        }
        else
        {
            added = add_recursive(data, current->right_child);
        }
        balance(current);
    }
    return added;
}



bool AVL::remove_recursive(int data, Node *&current)
{
    bool removed = false;
    
    if (data == current->data)
    {
        //If there are not any children, return false;
        if(current -> right_child == NULL && current -> left_child == NULL)
        {
            delete current;
            current = NULL;
            removed = true;
        }
        //One Child
        else if( (current -> right_child == NULL && current -> left_child != NULL )|| (current -> right_child != NULL && current -> left_child == NULL))
        {
            Node * temp = current;
            if(current -> left_child == NULL)
            {
                current = current->right_child;
            }
            else
            {
                current = current->left_child;
            }
            delete temp;
            temp = NULL;
            removed = true;
        }
        //Two Children
        else if(current -> right_child != NULL && current -> left_child != NULL)
        {
            removed = inorder_predecessor(current, current -> left_child);
        }

    }
    //if you have not found the node, recurse the tree until you find it.
    else
    {
        if(data > current->data)
        {
            removed = remove_recursive(data, current->right_child);
        }
        else
        {
            removed = remove_recursive(data, current ->left_child);
        }
    }
    
    if(current)
    {
        balance(current);
    }
    
    return removed;
}





bool AVL::inorder_predecessor(Node*& n1, Node*& n2)
{
    bool found;
    
    if(n2 -> right_child == NULL)
    {
        n1->data = n2->data;
        Node * temp = n2;
        n2 = n2->left_child;
        delete temp;
        temp = NULL;
        found = true;
    }
    else
    {
        found = inorder_predecessor(n1, n2->right_child);
    }
    
    if(n2)
    {
        balance(n2);
    }
        
    return found;
}






void AVL::clear(Node*& node)
{
    if( root != NULL)
    {
        if(node -> right_child != NULL)
        {
            clear(node->right_child);
        }
        else
        {
            clear(node->left_child);
        }
        delete node;
        node = NULL;
    }
}






void AVL::rotate_right(Node*& n)
{
    Node* temp = n-> left_child;
    n->left_child = temp ->right_child;
    temp->right_child = n;
    n = temp;
}





void AVL::rotate_left(Node*& n)
{
    Node* temp = n-> right_child;
    n->right_child = temp ->left_child;
    temp->left_child = n;
    n = temp;
}





bool AVL::find(int data, Node*& current)
{
    bool found;
    //return false if the value is not faound
    if (current == NULL)
    {
        found = false;
    }
    //return true if the value is found
    else if (current->data == data)
    {
        found = true;
    }
    else
    {
        //continues to search through the AVL tree recursively
        if ( data > current->data )
        {
            found = find(data, current->right_child);
        }
        else
        {
            found = find(data, current->left_child);
        }
    }
    
    return found;
}



void AVL::balance(Node*& n)
{
    int balanced = n->getBalance();
    if(balanced == 2)
    {
        if(n->right_child->getBalance() < 0)
        {
            rotate_right(n->right_child);
        }
        rotate_left(n);
    }
    else if(balanced == -2)
    {
        if(n->left_child->getBalance() > 0)
        {
            rotate_left(n->left_child);
        }
        rotate_right(n);
    }
}


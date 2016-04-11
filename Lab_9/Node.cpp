#include "Node.h"

int Node::max(int x, int y)
{
    int max = (x>y) ? x : y;
    /*
     ternary opporator. This is the same as saying:
     
     int max;
     if (x > y)
     {
     max = x;
     }
     else
     {
     max = y;
     }*/
    return max;
    
}

int Node::getHeight()
{
    int Height, Left_Height, Right_Height;
    Left_Height = left_child ? getMaxHeight(left_child) : 0;
    Right_Height = right_child ? getMaxHeight(right_child) : 0;
    
    Height = max(Left_Height, Right_Height);

    return Height;
}

int Node::getMaxHeight(Node* current)
{
    int left_height, right_height, height;
    
    left_height = current -> left_child ? getMaxHeight(current->left_child) + 1 : 0;
    right_height = current -> right_child ? getMaxHeight(current->right_child) + 1 : 0;
    height = max ( left_height, right_height);
    
    return height;
}

int Node::getBalance()
{
    int balance, left_height, right_height;
    left_height = left_child ? getMaxHeight(left_child) + 1: 0;
    right_height = right_child ? getMaxHeight(right_child) +1: 0;
    balance = right_height - left_height;
    
    return balance;
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Data;
typedef struct nd
{
    Data Value;
    struct nd* left;
    struct nd* right;
} Node;

Node* CreateNode( int val );

void AddLeftNode( Node* root, int val );

void AddRightNode( Node* root, int val );

void DeleteSubtree( Node* root );

void AddNodeSort( Node* root, int val);

void PrintInfix( Node* root );

int main()
{
    int data[] = {3, 2, 7, 4, 9, 8, 1, 5, 6};
    Node* root = CreateNode(data[0]);
    for (int i = 1; i < 9 ; ++i)
    {
        AddNodeSort(root, data[i]);
    }
    PrintInfix(root);
    return 0;
}

Node* CreateNode( int val )
{
    Node* newNode = (Node*) calloc(sizeof(Node), 1);
    newNode->Value = val;
    return newNode;
}

void AddLeftNode( Node* root, int val )
{
    assert(root);
    Node* Left = CreateNode(val);
    if (root -> left) DeleteSubtree(root -> left);
    root -> left = Left;
}

void AddRightNode( Node* root, int val )
{
    assert(root);
    Node* Right = CreateNode(val);
    if (root -> right) DeleteSubtree(root -> right);
    root -> right = Right;
}

void DeleteSubtree( Node* root )
{
    assert(root);
    if (root -> left)  DeleteSubtree(root -> left);
    if (root -> right) DeleteSubtree(root -> right);
    free(root);
}

void AddNodeSort( Node* root, int val)
{
    if (val >= root->Value)
    {
        if (!root -> right) AddRightNode(root, val);
        else AddNodeSort( root -> right, val);
    }
    else if (val < root -> Value)
    {
        if (!root -> left) AddLeftNode(root, val);
        else AddNodeSort( root -> left, val);
    }
}

void PrintInfix( Node* root )
{
    if (root -> left) PrintInfix(root -> left);
    printf("%d ", root -> Value);
    if (root -> right) PrintInfix(root -> right);
}
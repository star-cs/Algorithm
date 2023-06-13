#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    struct Node * left;
    struct Node * right;
    int weight;
}Node , *root;

int num = 0;

int get_WPL(Node* root , int height)
{   
    if(root->right == NULL && root->left == NULL)
    {
        num += root->weight * height;
    }
    if(root->left != NULL)
        get_WPL(root->left ,  height+1);
    if(root->right != NULL)
        get_WPL(root->right , height+1);

    return num;
}

/*
 * 创建二叉树结点
 */
Node *new_node(int weight) {
    auto *node = (Node *) malloc(sizeof(Node));
    node->weight = weight;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int main()
{
    // Node *root = new_node(1);
    // root->left = new_node(2);
    // root->right = new_node(3);
    // root->left->left = new_node(4);
    
    // get_WPL( root , 0);
    // cout << num;    //11

    // Node *root = new_node(3);
    // root->left = new_node(5);
    // root->right = new_node(8);
    // root->left->left = new_node(2);
    // root->left->right = new_node(12);
    // root->left->right->left = new_node(7);
    // get_WPL( root , 0);
    // cout << num;    //33

    Node *root = new_node(3);
    root->left = new_node(1);
    root->right = new_node(22);
    root->left->right = new_node(12);
    root->right->left = new_node(2);
    root->left->right->left = new_node(4);
    root->left->right->right = new_node(9);
    root->right->left->left = new_node(5);
    cout << get_WPL(root , 0) << endl;
    cout << num;        //54


    return 0;
}
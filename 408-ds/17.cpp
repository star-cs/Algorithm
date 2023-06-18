#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    char data[10];
    struct node * left , * right;
}BTree;

string ans;
//中序遍历
void  process1(BTree *root , int depth)
{
    if(root == NULL)
        return;
    else if(root->left == NULL && root->right == NULL)
        ans.append(root->data);
    else
    {
        if(depth > 1)   ans.append("(");
        process1(root->left , depth+1);
        ans.append(root->data);
        process1(root->right , depth+1);
        if(depth > 1)   ans.append(")");
    }
    
}

string process2(BTree *root)
{
    ans = "";
    process1(root , 1);
    return ans;
}
/**
 * 创建二叉树结点
 */
BTree *new_node_17(char data[]) {
    auto *node = (BTree *) malloc(sizeof(BTree));
    strcpy(node->data, data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    char add[] = "+", sub[] = "-", mul[] = "*";
    char a[] = "a", b[] = "b", c[] = "c", d[] = "d";
    BTree *root = new_node_17(mul);
    root->left = new_node_17(add);
    root->right = new_node_17(mul);
    root->left->left = new_node_17(a);
    root->left->right = new_node_17(b);
    root->right->left = new_node_17(c);
    root->right->right = new_node_17(sub);
    root->right->right->right = new_node_17(d);

    //"(a+b)*(c*(-d))"
    cout << process2(root);
}

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* create_node(int item)
{
    Node *new_node = new Node;

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left_child(Node *parent_node, Node *child)
{
    parent_node->left = child;
}

void add_right_child(Node *parent_node, Node *child)
{
    parent_node->right = child;
}

Node *bst_insert(Node *root, Node *node)
{
    Node *parent_node, *current_node;
    if(root==NULL)
    {
        root= node;
        return root;
    }

    parent_node= NULL;
    current_node=root;
    while(current_node != NULL)
    {
        parent_node = current_node;
        if(node->data<current_node->data)
        {
            current_node=current_node->left;
        }
        else
        {
            current_node=current_node->right;
        }
    }
    if(node->data<parent_node->data)
    {
        add_left_child(parent_node,node);
    }
    else
    {
        add_right_child(parent_node,node);
    }
    return root;
}

void pre_order(Node *node)
{
    printf("%d ",node->data);
    if(node->left != NULL)
        pre_order(node->left);
    if(node->right != NULL)
        pre_order(node->right);

}

int main()
{
    cout<<"Enter number of nodes :"<<endl;
    int n,data;
    cin>>n;
    Node *arr[n],*root;
    cout<<"Enter root :"<<endl;
    cin>>data;
    root=create_node(data);
    cout<<"Enter node data :"<<endl;
    for(int i= 1;i<n;i++)
    {
        cin>>data;
        arr[i]=create_node(data);
    }
    for(int i= 1;i<n;i++)
        bst_insert(root,arr[i]);
    cout<<endl;
    cout<<"Pre order traversal of bst :"<<endl;
    pre_order(root);
    cout<<endl;
    return 0;
}

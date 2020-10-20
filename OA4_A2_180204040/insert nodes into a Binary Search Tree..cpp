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

Node* create_tree()
{
    Node *eight = create_node(8);
    Node *three = create_node(3);
    Node *ten = create_node(10);
    add_left_child(eight, three);
    add_right_child(eight,ten);

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(three,one);
    add_right_child(three,six);

    Node *four = create_node(4);
    Node *seven = create_node(7);
    add_left_child(six,four);
    add_right_child(six,seven);

    Node *fourteen = create_node(14);
    add_right_child(ten,fourteen);

    Node *thirteen = create_node(13);
    add_left_child(fourteen,thirteen);

    return eight;
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
    Node *root = create_tree();
    cout<<"Pre order traversal of bst before insertion:"<<endl;
    pre_order(root);
    cout<<endl;
    cout<<"Enter number of node to insert:"<<endl;
    int data;
    Node *n;
    cin>>data;
    n=create_node(data);
    bst_insert(root,n);
    cout<<endl;
    cout<<"Pre order traversal of bst after insertion:"<<endl;
    pre_order(root);
    cout<<endl;
    return 0;
}


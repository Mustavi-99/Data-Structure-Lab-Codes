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

bool bst_search(Node *x,int key)
{
    while(x!=NULL)
    {
        if(x->data==key)
            return true;
        else if(x->data<key)
            x=x->right;
        else
            x=x->left;
    }
    return false;
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
    int key;
    cout<<"Enter node to be searched :"<<endl;
    cin>>key;
    /*cout<<"Pre order traversal of bst:"<<endl;
    pre_order(root);
    */cout<<endl;
    if(bst_search(root,key))
        cout<<"Key found"<<endl;
    else
        cout<<"Key not found"<<endl;
    return 0;
}


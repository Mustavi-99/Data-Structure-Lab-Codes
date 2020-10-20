#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
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
    if(child!=NULL)
    parent_node->left->parent=parent_node;
}

void add_right_child(Node *parent_node, Node *child)
{
    parent_node->right = child;
    if(child!=NULL)
    parent_node->right->parent=parent_node;
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
Node *bst_transplant(Node *root, Node *current_node, Node *new_node)
{

    if(current_node == root)
    {
        root = new_node;
    }
    else if (current_node==current_node->parent->left)
    {
        add_left_child(current_node->parent,new_node);
    }
    else
    {
        add_right_child(current_node->parent,new_node);
    }
    return root;
}

Node *bst_minimum(Node *root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;

}

Node *bst_delete(Node *root, Node *node)
{
    Node *smallest_node;
    if(node->left==NULL)
    {
        root= bst_transplant(root,node,node->right);
    }
    else if(node->right==NULL)
    {
        root= bst_transplant(root,node,node->left);
    }
    else
    {
        smallest_node= bst_minimum(node->right);
        if(smallest_node->parent != node)
        {
            root = bst_transplant(root, smallest_node,smallest_node->right);
            add_right_child(smallest_node,node->right);
        }
        root= bst_transplant(root,node,smallest_node);
        add_left_child(smallest_node,node->left);
    }
    free(node);
    return root;
}

Node *bst_search(Node *x,int key)
{
    while(x!=NULL)
    {
        if(x->data==key)
            return x;
        else if(x->data<key)
            x=x->right;
        else
            x=x->left;
    }
    return x;
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
    cout<<"Pre order traversal of bst before deletion:"<<endl;
    pre_order(root);
    cout<<endl;
    cout<<"Enter the node to be deleted :"<<endl;
    int key;
    cin>>key;
    Node *n=bst_search(root,key);
    if(n==NULL)
    {
        cout<<"The node doesn't exist"<<endl;
        return 0;
    }
    Node *n1=bst_delete(root,n);
    cout<<endl;
    cout<<"Pre order traversal of bst after deletion:"<<endl;
    pre_order(n1);
    cout<<endl;
    return 0;
}



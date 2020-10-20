#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

struct q
{
    Node *po;
};
struct q n[100];
int top = -1;

void push(Node *x)
{
    top = top+1;
    n[top].po=x;
}

Node *pop()
{
    Node *temp = n[0].po;
    for(int i=1;i<=top;i++)
        n[i-1]=n[i];
    top--;
    return temp;
}

bool isEmpty()
{
    if(top==-1)
        return true;
    return false;
}

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
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_child(two, seven);
    add_right_child(two,nine);

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven,one);
    add_right_child(seven,six);

    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_child(six,five);
    add_right_child(six,ten);

    Node *eight = create_node(8);
    add_right_child(nine,eight);

    Node *three = create_node(3);
    Node *four = create_node(4);
    add_left_child(eight,three);
    add_right_child(eight,four);

    return two;
}

void level_order(Node *node)
{
    push(node);
    Node *p;
    while(!isEmpty())
        {
            p=pop();
            if(p!=NULL)
            {
                cout<<p->data<<" ";
                push(p->left);
                push(p->right);
            }
        }
}

int main()
{
    Node *root = create_tree();
    cout<<"Level order traversal:"<<endl;
    level_order(root);
    return 0;
}

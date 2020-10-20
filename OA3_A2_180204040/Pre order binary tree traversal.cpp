#include<bits/stdc++.h>
using namespace std;

int top=-1;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
struct stc
{
    int st;
    Node *po;
};
struct stc s[100];

void push(Node *n,int x)
{
    if(top==100-1)
        cout<<"Overflow"<<endl;
    else
    {
        top=top+1;
        s[top].po=n;
        s[top].st=x;
    }
}

void pop()
{
    s[top--];
}

bool isEmpty()
{
    if(top==-1)
        return true;
    else
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
void pre_order(Node *node)
{
    Node *p;
    int i;
    push(node,1);
    while(!isEmpty())
    {
        p=s[top].po;
        i=s[top].st;
        pop();
        if(p!=NULL)
        {
            switch(i)
            {
            case 1:
                push(p,2);
                cout<<p->data<<" ";
                break;
            case 2:
                push(p,3);
                push(p->left,1);
                break;
            case 3:
                push(p->right,1);
                break;
            default:
                break;
            }

        }
    }
}
int main()
{
    Node *root = create_tree();
    cout<<"Pre order Traversal:"<<endl;
    pre_order(root);
    return 0;
}


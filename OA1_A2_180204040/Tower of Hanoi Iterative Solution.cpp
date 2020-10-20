#include<bits/stdc++.h>
using namespace std;

int sta[10000];
int top=-1;

void push(int x)
{
    if(top==10000-1)
        cout<<"Overflow in stack"<<endl;
    else
    {
        top++;
        sta[top]=x;
    }
}

int pop()
{
    return sta[top--];
}

bool isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}

void towerofhanoi(int a, int from, int aux, int to)
{
    push(a);
    push(from);
    push(aux);
    push(to);
    int a1;
    int from1;
    int aux1;
    int to1;

    while(!isEmpty())
    {
        to1=sta[top];
        pop();
        aux1=sta[top];
        pop();
        from1= sta[top];
        pop();
        a1=sta[top];
        pop();

        if(a1==1)
            cout<<"Move disk from "<<from1<<" to "<<to1<<"."<<endl;
        else
        {
            push(a1-1);
            push(aux1);
            push(from1);
            push(to1);

            push(1);
            push(from1);
            push(aux1);
            push(to1);

            push(a1-1);
            push(from1);
            push(to1);
            push(aux1);
        }
    }
}

int main()
{
    cout<<"Enter number of disks:"<<endl;
    int n;
    cin>>n;
    towerofhanoi(n,1,2,3);
    return 0;
}

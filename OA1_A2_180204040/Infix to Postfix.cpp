#include<bits/stdc++.h>
using namespace std;

char sta[20];
int top=-1;

void push(char x)
{
    if(top==20-1)
        cout<<"Overload"<<endl;
    else
    {
        top++;
        sta[top]=x;
    }
}

int pop()
{
    return top--;
}

int prec(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}
void infixtopostfix(string s)
{
    string p;
    s='('+s+')';
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
        {
            p+=s[i];
        }
        else if(s[i]=='(')
                push(s[i]);
        else if(s[i]==')')
        {
            while(sta[top]!='(')
            {
                p+=sta[top];
                pop();
            }
            if(sta[top]=='(')
            {
                pop();
            }
        }
        else
        {
            while(prec(s[i])<=prec(sta[top])&&sta[top]!='(')
            {
                p+=sta[top];
                pop();
            }
            push(s[i]);
        }

    }
    cout<<"Infix to postfix expression: "<<endl;
    cout<<p<<endl;
}
int main()
{
    string s;
    cout<<"Enter expression: "<<endl;
    getline(cin,s);
    infixtopostfix(s);
    return 0;
}

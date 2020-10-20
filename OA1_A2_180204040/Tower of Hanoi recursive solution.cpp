#include<bits/stdc++.h>
using namespace std;
int c=0;
void towerofhanoi(int a, char from, char aux, char to)
{

    if(a==1)
    {
        cout<<"Move disk from "<<from<<" to "<<to<<endl;
        c++;
        return;
    }
    towerofhanoi(a-1,from,to,aux);
    cout<<"Move disk from "<<from<<" to "<<to<<endl;
    c++;
    towerofhanoi(a-1,aux,from,to);
}

int main()
{
    int n;
    cout<<"Enter number of discs"<<endl;
    cin>>n;
    towerofhanoi(n,'1','2','3');
    cout<<"Total turns= "<<c<<endl;
    return 0;
}

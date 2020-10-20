#include<bits/stdc++.h>
using namespace std;

int graph[20][20],visited[20], node, edge, i, j,flag=0;


void dfs(int v)
{
    int j,k;
    visited[v]=1;
    cout<<v<<"-> ";
    for(k=1;k<v;k++)
    {
        if(graph[v][k])///cycle detection
            flag=1;
    }
    for(j= 1;j<=node;j++)
    {
        if(graph[v][j] && !visited[j])
        {
            dfs(j);
        }

    }


}

int main()
{
    cout<<"Enter number of nodes :"<<endl;
    cin>>node;
    cout<<"Enter number of edges :"<<endl;
    cin>>edge;

    int so, des;
    for(i=1;i<=edge;i++)
    {
        cin>>so;
        cin>>des;
        graph[so][des]=1;
    }


    ///for printing graph
    for(i=1; i<=node;i++)
    {
        for(j=1;j<=node;j++)
        cout<<graph[i][j]<<"\t";
        cout<<endl;
    }

    int v;
    cout<<"Enter starting node: "<<endl;
    cin>>v;
    cout<<"DFS Traversal: "<<endl;
    dfs(v);
    if(flag==1)
        cout<<"\n\nCycle detected"<<endl;
    else
        cout<<"\n\nNo Cycle detected"<<endl;
    return 0;

}

#include<bits/stdc++.h>
using namespace std;
int graph[20][20],visited[20],node,edge,i,j,flag=0;

void dfs_search(int v,int s)
{
    if(v==s)
        flag=1;
    visited[v]=1;
    cout<<v<<"-> ";
    int j;
    for(j=1; j<=node;j++)
        if(graph[v][j] && !visited[j])
        {
            dfs_search(j,s);
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

    for(i=1;i<=node;i++)
    {
        for(j=1;j<=node;j++)
            cout<<graph[i][j]<<"\t";
        cout<<endl;
    }
    int v,s;
    cout<<"Enter starting node :"<<endl;
    cin>>v;
    cout<<"Enter the element to be searched :"<<endl;
    cin>>s;
    cout<<"DFS Traversal :"<<endl;
    dfs_search(v,s);
    if(flag== 1)
        cout<<"\n\nElement found."<<endl;
    else
        cout<<"\n\nElement not found."<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int graph[20][20],visited[20],qu[20],orig[20],node,edge,i,j,r=-1,f=0,k=-1,start_node,end_node,o[20],m;

void shortest_path(int sp)
{
    cout<<"\n\nShortest path:\n"<<end_node<<" < ";
    while(orig[sp]!=start_node)
    {
        for(i=0;i<=r;i++)
    {
            if(qu[o[i]]==orig[sp])
        {
            cout<<orig[sp]<<" < ";
            sp=o[i];

        }
    }
    }
    cout<<start_node<<endl;
}

void bfs(int v,int n)
{
    for(i=1;i<=node;i++)
        if(graph[v][i] && !visited[i])
        {
            qu[++r]=i;
            orig[r]=v;
        }
    if(f<=r)
    {
        if(visited[qu[f]] != 1)
        {
            visited[qu[f]]=1;
            o[++k]=f;
           cout<<qu[f]<<",";
        }
        if(qu[f]==n)
        {
            m=f;
            n=1;
            ///to traverse till the short node
            //return;
        }
        bfs(qu[f++],n);

    }

}

int main()
{
    cout<<"Enter number of nodes :"<<endl;
    cin>>node;
    cout<<"Enter number of edges :"<<endl;
    cin>>edge;
    int so,des;
    for(i=1;i<=edge;i++)
        {
            cin>>so;
            cin>>des;
            graph[so][des]=1;
        }

    ///for printing the graph
    /*for(i=1; i<=node;i++)
    {
        for(j=1;j<=node;j++)
            cout<<graph[i][j]<<"\t";
        cout<<endl;
    }*/
    cout<<"\nEnter the starting node :"<<endl;
    cin>>start_node;
    visited[start_node]=1;
    cout<<"The node for the shortest path :"<<endl;
    cin>>end_node;
    cout<<"Level order traversal :\n"<<start_node<<",";
    bfs(start_node,end_node);
    shortest_path(m);
    return 0;
}

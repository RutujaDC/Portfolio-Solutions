#include<iostream>
#include<limits.h>
#include<queue>
#include<vector>
using namespace std;
int n=6;
vector<vector<int>>graph;
vector<vector<int>>resGraph;
vector<int>parent(n);
bool bfs(int s,int t)
{
    vector<bool>visited(n,false);
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while (!q.empty())
        {
        int u=q.front();
        q.pop();
        for(int v=0;v<n;++v)
        {
            if(!visited[v]&&resGraph[u][v]>0)
            {
                if(v==t)
                {
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return false;
}
int fordFulkerson(int s,int t)
{
    resGraph=graph;
    int maxFlow=0;
    while(bfs(s,t))
        {
        int pathFlow=INT_MAX;
        for (int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            pathFlow=min(pathFlow,resGraph[u][v]);
        }
        for (int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            resGraph[u][v]-=pathFlow;
            resGraph[v][u]+=pathFlow;
        }

        maxFlow+=pathFlow;
    }

    return maxFlow;
}

int main()
{
    graph={
        {0,6,2,0,0,0},
        {0,0,0,2,0,0},
        {0,3,0,0,3,5},
        {0,0,0,0,3,5},
        {0,0,0,0,0,5},
        {0,0,0,0,0,0}
    };
    cout<<"Adjacency matrix:"<<endl;
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<n;j++)
         {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    int src,dest;
    cout<<"Enter source and destination: ";
    cin>>src>>dest;
    cout<<"The maximum possible flow is "<<fordFulkerson(src,dest)<<endl;

    return 0;
}

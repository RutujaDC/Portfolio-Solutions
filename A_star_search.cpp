#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> >graph;
void A_StarSearch(int src,int dest)
{
    int n=7;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>cost(n,999);
    vector<int>parent(n,-1);
    cost[src]=0;
    pq.push({0,src});
    while (!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if (u==dest)
        {
            cout<<"Shortest path cost from "<<src<<" to "<<dest<<": "<<cost[u]<<endl;
            cout<<"Path: ";
            int n1=dest;
            vector<int>path;
            while(n1!=-1)
             {
                path.push_back(n1);
                n1=parent[n1];
            }
            for(int i=path.size()-1;i>=0;i--)
           {
                cout<<path[i]<<"->";
            }
            cout<<endl;
            return;
        }
        for(int v=0;v<n;v++)
        {
            if (graph[u][v]!=999)
            {
                int newC=cost[u]+graph[u][v];
                int heuristic=abs(dest-v);
                if (newC<cost[v]) {
                    cost[v]=newC;
                    parent[v]=u;
                    pq.push({newC+heuristic,v});
                }
            }
        }
    }
}

int main()
{
      int n=7,s,d;
    cout<<"This example considers 7 nodes"<<endl;
    graph.resize(n+1,vector<int>(n+1));
    graph={
        {0,3,2,999,999,999,999},
        {3,0,6,1,4,999,999},
        {2,6,0,999,999,3,5},
        {999,1,999, 0,2,999,999},
        {999,4,999,2,0,2,5},
        {999,999,3,999,2,0,7},
        {999,999,5,999,5,7,0}
    };
    cout<<"The adjacency matrix be: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"The nodes are 0,1,..6"<<endl;
    cout<<"Enter the source node and destination node!"<<endl;
    cin>>s>>d;
    A_StarSearch(s,d);
    return 0;
}

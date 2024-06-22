#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge
{
    int u;
    int v;
    int weight;
    Edge(int u,int v,int weight)
    {
        this->u=u;
        this->v=v;
        this->weight=weight;
    }
};
vector<Edge> edges;
bool compare(struct Edge &e1, struct Edge &e2) {
    return e1.weight<e2.weight;
}
int root(int arr[],int i)
{
    while(i!=arr[i])
    {
        i=arr[i];
    }
    return i;
}
void unionFun(int arr[],int u,int v)
{
    int ru=root(arr,u);
    int rv=root(arr,v);
    arr[ru]=arr[rv];
}
int find(int arr[],int u,int v)
{
    if(root(arr,u)==root(arr,v))
        return 1;
    else
        return 0;
}
int main()
{
    cout<<"Enter the number of vertices and Edges "<<endl;
    int m,n,x,y,z;
    cin>>m>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        edges.push_back(Edge(x,y,z));
    }
    sort(edges.begin(),edges.end(),compare);
    cout << "Edges sorted by weight:"<<endl;

     for(int i=0;i<m;i++)
    {
        arr[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        int f=find(arr,edges[i].u,edges[i].v);
        if(f==0)
        {
            cout<<"edge "<<i+1<<": "<<edges[i].u<<"-->"<<edges[i].v<<"  weight:"<<edges[i].weight<<endl;
            unionFun(arr,edges[i].u,edges[i].v);
        }
    }


    return 0;
}

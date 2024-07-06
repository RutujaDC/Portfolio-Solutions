#include<iostream>
using namespace std;
#include<vector>
vector<vector<int> >arr;
int mininum(int d[],int n,int c[])
{
    int min=0,j;
       for(int l=0;l<n;l++)
    {
        if(c[l]==0)
        {min=l;
        break;}
    }

    for(j=0;j<n;j++)
    {
        if(d[j]<d[min]&&c[j]!=1)
        {
            min=j;
        }
    }return min;
}
void dijkstra(int src,int d[],int p[],int n,int c[])
{
int m,i;

    for(i=0;i<n;i++)
    {
        c[i]=0;
    }
    m=src;
    for(i=0;i<n;i++)
    {
        d[i]=arr[m][i];

    }
    for(i=0;i<n;i++)
    {
        p[i]=m;
    }
    c[m]=1;
    for(int k=0;k<n-1;k++)
    {
    int min=mininum(d,n,c);
    c[min]=1;
   // printf("(%d,%d)\n",p[min],min);
         for(i=0;i<n;i++)
        {
            if(d[i]>arr[min][i]+d[min]&&c[i]!=1)
            {
                d[i]=arr[min][i]+d[min];
                p[i]=min;
            }
        }
    }
    cout<<endl<<"Distance from source to all other nodes:"<<endl;
      for(i=0;i<n;i++)
    {
        printf("(%d %d)-->%d \n",m,i,d[i]);
    }
}

int main()
{
    int n=7,s;
    int d[100],p[100],c[100];
    cout<<"This example considers 7 nodes"<<endl;
    arr.resize(n+1,vector<int>(n+1));
    cout<<"The adjacency matrix be: "<<endl;
     arr={
        {0,3,2,999,999,999,999},
        {3,0,6,1,4,999,999},
        {2,6,0,999,999,3,5},
        {999,1,999, 0,2,999,999},
        {999,4,999,3,0,2,5},
        {999,999,3,999,2,0,7},
        {999,999,5,999,5,7,0}
    };
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"The nodes are 0,1,..6"<<endl;
    cout<<"Enter the source node to start with!"<<endl;
    cin>>s;
    dijkstra(s,d,p,n,c);
    return 0;

}

#include<iostream>
#include<vector>
using namespace std;
vector<int>BIT;
int n;
void update(int index,int value)
{
    while(index<=n)
    {
        BIT[index]+=value;
        index+=index&-index;
    }
}

int query(int index)
{
    int sum=0;
    while(index>0)
        {
        sum+=BIT[index];
        index-=index&-index;
    }
    return sum;
}

int rangeQuery(int left,int right)
{
    return query(right)-query(left-1);
}

int main()
{
    int size;
    cout<<"Enter the size of the BIT:";
    cin>>size;
    n=size;
    BIT.resize(n+1,0);
    while(1)
    {
        int op;
        cout<<"Enter operation \n1: Update\n 2: Query\n 3: Range Query\n 4: Exit\n: ";
        cin>>op;
        if(op==4)
        break;
        int index,value;
        switch(op)
        {
            case 1:
                cout<<"Enter index and value to update: ";
                cin>>index>>value;
                update(index,value);
                break;
            case 2:
                cout<<"Enter index to query: ";
                cin>>index;
                cout<<"Sum up to index "<<index<<" is: "<<query(index)<<endl;
                break;
            case 3:
                cout<<"Enter left index for range query: ";
                cin>>index;
               int right;
               cout<<"Enter right index for range query: ";
            cin>>right;
            cout<<"Sum from index "<<index<<" to "<<right<<" is: "<<rangeQuery(index,right)<<endl;
                break;
            default:
                cout<<"Invalid operation"<< endl;
        }
    }

    return 0;
}

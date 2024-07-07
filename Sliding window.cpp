#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void addPacket(queue<int>& trafficWindow,int &currentSum,int windowSize,int threshold,int packetSize)
{
    trafficWindow.push(packetSize);
    currentSum+=packetSize;

    if(trafficWindow.size()>windowSize)
    {
        currentSum-=trafficWindow.front();
        trafficWindow.pop();
    }
    if (currentSum>threshold)
    {
        cout<<"Congestion detected!  Current sum: "<<currentSum<<endl;
    }
    else
        {
        cout<<"No congestion detected. Current sum: " <<currentSum<<endl;
    }
}

int main()
{
    int windowSize=5;
    int threshold=100;
    queue<int>trafficWindow;
    int currentSum=0;
    cout<<"window size is 5 and threshold set is 100"<<endl;
    vector<int>trafficData={20,30,40,30,40,15,10,5};
    for(int packetSize:trafficData)
    {
        addPacket(trafficWindow,currentSum,windowSize,threshold,packetSize);
    }

    return 0;
}

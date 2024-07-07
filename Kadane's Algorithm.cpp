#include<iostream>
#include<vector>
using namespace std;
vector<int>network;
int kadane(vector <int> &nums)
{
    int max_sum=nums[0];
    int current_sum=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        current_sum=max(nums[i],current_sum+nums[i]);
        max_sum=max(max_sum,current_sum);
    }
    return max_sum;
}

int main() {
    network={1,-3,2,1,-1,3,-2,3,-5,4};
    cout<<"Maximum traffic volume: "<<kadane(network)<<endl;
    return 0;
}

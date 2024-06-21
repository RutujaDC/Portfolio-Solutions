#include <iostream>
#include <vector>
using namespace std;
vector<int>costs,performance;
int autoscaling(int budget)
{
    int n=costs.size();
    vector<vector<int> >dp(n+1,vector<int>(budget+1,0));
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=budget;j++)
        {
            if (costs[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-costs[i-1]]+performance[i-1]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][budget];
}

int main()
 {
    int budget, n;
    cout << "Enter the maximum budget:";
    cin >> budget;
    cout << "Enter the number of instances:";
    cin >> n;
    costs.resize(n);
    performance.resize(n);
    cout <<"Enter the costs of the instances:";
    for (int i=0;i<n;i++)
    {
        cin>>costs[i];
    }
    cout <<"Enter the performance values of the instances:";
    for (int i=0;i<n;i++)
    {
        cin >>performance[i];
    }
    int maxPerformance=autoscaling(budget);
    cout <<"Maximum achievable performance within the budget:"<<maxPerformance<<endl;
    return 0;
}

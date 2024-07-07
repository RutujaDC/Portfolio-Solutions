#include<iostream>
#include<vector>
using namespace std;
int LCS(string text1,string text2)
{
    int m=text1.size();
    int n=text2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string text1;
    string text2;
    cin>>text1>>text2;
    int lcsLength=LCS(text1,text2);
    cout<<"Length of Longest Common Subsequence: "<<lcsLength<<endl;
    return 0;
}

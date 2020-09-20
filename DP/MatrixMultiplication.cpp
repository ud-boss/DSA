#include<bits/stdc++.h>
using namespace std;

int GetMinCost(vector<int> A)
{
    int N = A.size();
    cout<<N<<endl;
    vector<vector<int> > DP(N,vector<int>(N,0));
    for(int len=2;len<N;len++)
    {
        for(int i=1;i<N-len+1;i++)
        {
            int j = i+len-1;
            DP[i][j] = INT_MAX;
            for(int k=i;k<j;k++)
            {
                DP[i][j] = min(DP[i][j],DP[i][k] + DP[k+1][j] + A[i-1]*A[j]*A[k]);
            }
        }
    }
    return DP[1][N-2];
}

int powerOfTwo(int N)
{
    int ans = 0;
    while(N != 0)
    {
        ans = N;
        N = N & (N-1);
    }
    return ans;
}

int main()
{
    cout<<powerOfTwo(29);
    return 0;
}

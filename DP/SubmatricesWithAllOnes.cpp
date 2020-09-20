#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A)
{
    int r = A.size();
    int c = A[0].size();
    vector<vector<int> > Rt(r,vector<int>(c,0));
    for(int i=0;i<r;i++)
    {
        Rt[i][c-1] = A[i][c-1];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=c-2;j>=0;j--)
        {
            if(A[i][j] == 0)
                Rt[i][j] = 0;
            else
                Rt[i][j] = 1 + Rt[i][j+1];
        }
    }
    int ans = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int x = INT_MAX;
            for(int k=i;k<r;k++)
            {
                x = min(x,Rt[k][j]);
                ans +=x;
            }
        }
    }
   return ans;
}

int main()
{
    vector<vector<int > > A{{1,0,1},{1,1,0},{1,1,0}};
    cout<<solve(A);
    return 0;
}

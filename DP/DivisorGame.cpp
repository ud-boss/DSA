#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{
    int N = A.size();
        vector<int> Dp(N,1);

        for(int i=1;i<N;i++)
        {
            if(A[i] > A[i-1])
              Dp[i] = Dp[i-1]+1;
            else if(A[i] == A[i-1])
                Dp[i] = Dp[i-1];
        }

        for(int i=N-1;i>0;i--)
        {
            if(A[i-1] > A[i])
                Dp[i-1] = max(Dp[i]+1,Dp[i-1]);
            else if(A[i-1] == A[i])
                Dp[i-1] = Dp[i];
        }
        int res = 0;
        for(int a : Dp)
            res += a;
        return res;
}

int main()
{
   string str = "1,2,3,3,1";
   for(char &c : str)
   {
       if(c == ',')
          c = ' ';
   }
   vector<int> A;
   stringstream is(str);
   int x;
   while(is>>x)
   {
       A.push_back(x);
   }
   cout<<solve(A)<<endl;
    return 0;
}

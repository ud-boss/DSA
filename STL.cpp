#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> &A)
{
    int N = A.size();
    int ans = 0;
    for(int i=1;i<N;i++)
    {
        ans += abs(A[i-1]-A[i]);
    }
    return ans;
}

int main()
{
    int N;
    cin>>N;
    int cnt = 1;
    while(cnt <= N)
    {
        int M,P;
        cin>>M>>P;
        vector<int> A(M,0);
        for(int i=0;i<M;i++)
        {
            cin>>A[i];
        }
        cout<<"Case "<<cnt<<":"<<endl;
        while(P--)
        {
            int z,t;
            cin>>z>>t;
            for(int i=0;i<M;i++)
            {
                if(A[i] == z)
                    A[i] = t;
            }
            cout<<helper(A)<<endl;
        }
        cnt++;
    }
    return 0;
}

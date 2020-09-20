#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> A)
{
    int N = A.size();
    int currMax = A[0];
    for(int i=1;i<N;i++)
    {
        if(currMax < i)
            return false;
        currMax = max(currMax,i+A[i]);
    }
    return true;
}

int minJump(vector<int> A)
{
    int N = A.size();
    int currMax = A[0];
    int maxJump = A[0];
    int jump = 1;
    for(int i=1;i<N;i++)
    {
        currMax = max(currMax,i+A[i]);
        if(i == maxJump)
        {
            jump++;
            maxJump = currMax;
        }
    }
    return maxJump >= N-1 ? jump : -1;
}

int main()
{
    vector<int> A({1,2,5,6,0});
    cout<<(canJump(A) ? "YES" : "NO")<<endl;
    cout<<minJump(A)<<endl;
    return 0;
}

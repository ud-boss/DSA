#include<bits/stdc++.h>
using namespace std;


int helperMinJump(vector<int> &A,int maxIndex)
{
    queue<pair<int,int> > Q;
    unordered_set<int> S;
    int N = A.size();
    Q.push({maxIndex,1});
    S.insert(maxIndex);
    while(!Q.empty())
    {
        pair<int,int> p = Q.front();
        Q.pop();
        int index = p.first;
        int cnt = p.second;
        int left = A[index] < index ? index-A[index] : N-(A[index]-index);
        int right = (A[index]+index)%N;
        if(left == maxIndex || right == maxIndex)
            return cnt;
        if(S.insert(left).second)
          Q.push({left,cnt+1});
        if(S.insert(right).second)
          Q.push({right,cnt+1});
    }
    return -1;
}

void minJump(vector<int> A)
{
    int N = A.size();
    int maxIndex = 0;
    int Max = A[0];
    for(int i=1;i<N;i++)
    {
        if(Max < A[i])
        {
            Max = A[i];
            maxIndex = i;
        }
    }
    cout<<maxIndex<<endl;
    cout<<helperMinJump(A,maxIndex);
}

int main()
{
    vector<int> A{1,7,1,1,1,1};
    minJump(A);
    return 0;
}

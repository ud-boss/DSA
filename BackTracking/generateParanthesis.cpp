#include<bits/stdc++.h>
using namespace std;

void helper(int max,int open,int close,string temp,vector<string> &ans)
{
    if(temp.length() == 2*max)
        ans.push_back(temp);
    if(open > 0)
    {
       helper(max,open-1,close,temp + '(',ans);
    }
    if(close > open)
        helper(max,open,close-1,temp+')',ans);
}

vector<string> generateParenthesis(int N)
{
    vector<string> ans;
    string temp = "";
    helper(N,N,N,temp,ans);
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
    vector<string> ans = generateParenthesis(N);
    for(string x : ans)
        cout<<x<<endl;
    }
    return 0;
}

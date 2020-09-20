#include<bits/stdc++.h>
using namespace std;

bool helper(string s1,int index,int idx,vector<bool> &visited,string &ans,int N)
{
    if(visited[idx])
        return false;
    visited[idx] = true;
    ans += ('a'+ idx);
    if(ans.size() == N+1)
        return true;
    for(int i=0;i<N+1;i++)
    {
        if(visited[i] || index >= N)
           continue;
        char x = s1[index];
        char n = ('a'+ i);
        if(x == '>' && ans.back() > n || x == '<' && ans.back() < n)
        {
            if(helper(s1,index+1,i,visited,ans,N))
               return true;
        }
    }
    ans.pop_back();
    visited[idx] = false;
    return false;
}

string smallestString(string str)
{
    int N = str.length();
    vector<bool> visited(N+1,false);
    for(int i=0;i<N+1;i++)
    {
        if(!visited[i])
        {
            string ans = "";
            if(helper(str,0,i,visited,ans,N))
                return ans;
        }
    }
    return "NHI HUA";
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        cout<<smallestString(str)<<endl;
    }
    return 0;
}

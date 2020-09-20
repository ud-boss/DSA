#include<bits/stdc++.h>
using namespace std;

string SearchingChallenge(string str)
{
    string ans = "";
    int len = 0;
    int K = str[0]-'0';
    int end = 1,start = 1;
    int N = str.length();
    unordered_map<char,int> M;
    int count = 0;
    while(end < N)
    {
        M[str[end]]++;
        if(M[str[end]] == 1)
            count++;
        end++;
        while(count > K)
        {
            M[str[start]]--;
            if(M[str[start]] == 0)
                count--;
            start++;
        }
        if(len < end-start)
        {
            len = end-start;
            ans = str.substr(start,len);
        }
    }
    cout<<len<<endl;
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
      string str;
      cin>>str;
      cout<<SearchingChallenge(str)<<endl;
    }
    return 0;
}

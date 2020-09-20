#include<bits/stdc++.h>
using namespace std;


int wordSearch(string start,string target,vector<string> &dict)
{
    set<string> S;
    for(string str : dict)
    {
        S.insert(str);
    }
    if(S.find(target) == S.end())
    {
       cout<<"target not present"<<endl;
       return -1;
    }
    queue<string> Q;
    Q.push(start);
    int ans = 0;
    while(!Q.empty())
    {
        int sz = Q.size();
        while(sz--)
        {
            ans++;
            string word = Q.front();
            Q.pop();
            for(int i=0;i<word.size();i++)
            {
                char c = word[i];
                for(char j='A';j<='Z';j++)
                {
                    word[i] = j;
                    if(word == target)
                        return ans + 1;
                    if(S.find(word) != S.end())
                    {
                        cout<<word<<" ";
                        S.erase(word);
                       Q.push(word);
                    }
                }
                word[i] = c;
            }
        }
    }
    return -1;
}

int main()
{
    vector<string> dict{"POON","PLEE","SAME","POIE","PLIE","PLEA","POIN"};
    string start = "TOON";
    string target = "PLEA";
    cout<<wordSearch(start,target,dict)<<endl;
    return 0;
}

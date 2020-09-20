#include<bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> *par;
    vector<int> *rank;
    int getParent(int x)
    {
        while(par->at(x) != x)
        {
            x = par->at(x);
        }
        return x;
    }
public:
    UnionFind(int N)
    {
        par = new vector<int>(N+1,0);
        for(int i=0;i<=N;i++)
        {
            par->at(i) = i;
        }
        rank = new vector<int>(N+1,0);
    }
    ~UnionFind()
    {
        delete(par);
        delete(rank);
    }
    void Union(int a,int b)
    {
        int parA = getParent(a);
        int parB = getParent(b);
        if(parA != parB)
        {
            if(rank->at(parA) > rank->at(parB))
            {
                par->at(b) = ParA;
            }
            else if(rank->at(parA) < rank->at(parB))
            {
                par->at(a) = ParB;
            }
            else
            {
                par->at(b) = ParA;
                rank->at(a)++;
            }
        }
    }

    bool isSameSet(int a,int b)
    {
        int parA = getParent(a);
        int parB = getParent(b);
        return parA == parB;
    }

};

void check(int a,int b)
{
    cout<<
}

int main()
{
   UnionFind u(10);

    return 0;
}

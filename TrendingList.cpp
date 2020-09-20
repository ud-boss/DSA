#include<bits/stdc++.h>
using namespace std;

class TrendingList
{
 private:
    unordered_map<char,int> Values;
    map<int,list<char>,greater <int> > Keys;
    unordered_map<char,list<char>::iterator > Itr;
    int size,cap;
 public:
    TrendingList(int capacity):cap(capacity)
    {
        size = 0;
    }
 void update(char key,int val)  //log(N)
 {
     if(Values.find(key) != Values.end())
     {
         int freq = Values[key];
         Values[key] = val;
         auto it = Itr[key];
         Keys[freq].erase(it);
         Keys[val].push_back(key);
         Itr[key] = prev(Keys[freq].end());
     }
     else
     {
         if(size == cap)
         {
             auto it = prev(Keys.end());
             int minFreq = it->first;
             char minKey = it->second.front();
             it->second.pop_front();
             if(it->second.empty())
             {
                 Keys.erase(minFreq);
             }
             Itr.erase(minKey);
             Values.erase(minKey);
         }
         else
            size++;
         Keys[val].push_back(key);
         Itr[key] = prev(Keys[val].end());
         Values[key] = val;
     }
 }
 vector<pair<char,int> > get() //O(N)
 {
     vector<pair<char,int> > ans;
     for(auto it = Keys.begin();it != Keys.end();it++)
     {
         int cnt = it->first;
         for(auto iit=it->second.begin();iit!=it->second.end();iit++)
         {
             ans.push_back({*iit,cnt});
         }
     }
     return ans;
  }
};

void printVector(vector<pair<char,int> > V)
{
    for(auto x : V)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<"------------------"<<endl;
}

int main()
{
    TrendingList T(4);
    T.update('A',100);
    T.update('B',90);
    T.update('C',80);
    T.update('D',70);
    printVector(T.get());
    T.update('A',10);
    printVector(T.get());
    T.update('E',20);
    printVector(T.get());
    T.update('A',21);
    printVector(T.get());
    T.update('D',1);
    printVector(T.get());
    T.update('E',2);
    printVector(T.get());
    return 0;
}

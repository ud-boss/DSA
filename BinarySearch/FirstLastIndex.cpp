#include<bits/stdc++.h>
using namespace std;

int findFirst(vector<int> A,int T)
{
    int N = A.size();
    int low = 0,high = N-1;
    while(low < high)
    {
        int mid = (high-low)/2 + low;
        if(A[mid] < T)
            low = mid+1;
        else
            high = mid;
    }
    return A[high] == T ? high : -1;
}

int findLast(vector<int> A,int T)
{
    int N = A.size();
    int low = 0,high = N-1;
    while(low < high)
    {
        int mid = (high-low+1)/2 + low;
        if(A[mid] > T)
            high = mid-1;
        else
            low = mid;
    }
    return A[low] == T ? low : -1;
}

int main()
{
    vector<int> A({7,9,9,9,9});
    cout<<findFirst(A,7)<<endl;
    cout<<findLast(A,7)<<endl;
    return 0;
}

/*
Find the smallest positive missing number in the given array.
Example: [0, -10, 1, 3, -20], Ans = 2
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int mini,maxi;
    mini = INT_MAX;
    maxi = INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            maxi = max(maxi,a[i]);
            mini = min(mini,a[i]);
        }
    }
    if(mini == INT_MAX and maxi == INT_MIN)
    {
        cout<<0<<endl;
        return 0;
    }
    bool c[maxi-mini+1] = {false};
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            c[a[i]-mini] = true;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(c[i] == false)
        {
            cout<<mini+i<<endl;
            break;
        }
    }
    return 0;
}

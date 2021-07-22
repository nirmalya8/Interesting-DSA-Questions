/*
Problem:
Given an array a[] of size n. Output sum of each subarray of the given array.
Input
1 2 2
Output
1
3
5
2
4
2
*/
#include<iostream>
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
    for(int i=0;i<n;i++)
    {
        int s=0;
        for(int j=i;j<n;j++)
        {
            if(j==i)
            {
                s = a[j];
            }
            else
            {
                s = s+a[j];
            }
            cout<<s<<endl;
        }
    }
    return 0;
}

/*
Problem:
An arithmetic array is an array that contains at least two integers and the
differences between consecutive integers are equal. For example, [9, 10], [3, 3, 3],
and [9, 7, 5, 3] are arithmetic arrays, while [1, 3, 3, 7], [2, 1, 2], and [1, 2, 4] are
not arithmetic arrays.
Sarasvati has an array of N non-negative integers. The i-th integer of the array is
Ai. She wants to choose a contiguous arithmetic subarray from her array that has
the maximum length. Please help her to determine the length of the longest
contiguous arithmetic subarray.

Input
The first line of the input gives the number of test cases, T. T test cases follow.
Each test case begins with a line containing the integer N. The second line
contains N integers. The i-th integer is Ai.
Output
For each test case, output one line containing Case #x: y, where x is the test case
number (starting from 1) and y is the length of the longest contiguous arithmetic
subarray.

Input:
4
7
10 7 4 6 8 10 11
4
9 7 5 3
9
5 5 4 5 5 5 4 5 6
10
5 4 3 2 1 2 3 4 5 6
Output:
Case #1: 4
Case #2: 4
Case #3: 3
Case #4: 6
  
*/

#include<iostream>
using namespace std;
int main()
{
    int t,n;
    int q=0;
    cin>>t;
    while(t>0)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int j=2;
        int diff = a[1]-a[0];
        int currlong=2;
        int ans = 2;
        while(j<n)
        {
            if(a[j]-a[j-1] == diff)
            {
                currlong++;
            }
            else
            {
                currlong=2;
                diff = a[j]-a[j-1];
            }
            if(ans<currlong)
            {
                ans=currlong;
            }
             

            j++;
        }
        q++;
        cout<<"Case #"<<q<<": "<<ans<<endl;

        t--;
    
    }

    return 0;
}
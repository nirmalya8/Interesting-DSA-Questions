/*  
    Problem Statement: 
    Given an array, find out how many times it has to been rotated 
    from its initial sorted position.

    Input-Output:
    Eg. [11,12,15,18,2,5,6,8]
    It has been rotated: 4 times
    (One rotation means putting the first element to the end)

    Logic: 
    The position of the minimum element will give the number of times the array has been rotated
    from its initial sorted position. Finding the minimum element will take O(N) time but, we can
    use Binary Search to find the mimimum element, we can reduce the complexity to O(log N).

    If we look at the rotated array, to identify the minimum element (say a[i]), we observe that
    a[i-1]>a[i]<a[i+1].
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Taking Inputs
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }  
    // performing binary search to find the minimum element
    int low = 0;
    int high = n-1;
    int mid; // low + (high-low)/2 = (low + high)/2
    int i=0;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        i++;
        if(a[mid]<a[mid-1] and a[mid]<a[mid+1])
        {
            break;
        }
        else if(a[mid]>a[mid-1] and a[mid]<a[mid+1])
        {
            high = mid+1;
        }
        else if(a[mid]>a[mid-1] and a[mid]>a[mid+1])
        {
            low = mid-1;
        }
    }
    
    cout<<mid<<endl;
    
    return 0;
}

/*  
    Problem Statement: 
    Given a rotated sorted array(rotated from its initial sorted position.),
    search for an element. 

    Input-Output:
    Eg. [11,12,15,18,2,5,6,8]
    Search Element: 6
    Position: 6
    (One rotation means putting the first element to the end)

    Logic: 
    Binary search has to be modified to get the position of an element in a rotated
    sorted array, in the same way as it was done in rotateArray.cpp .

    If we look closely, we have two sorted arrays, one from position 0 to position of
    minimum element -1 and the other from position of minimum element to the end. 
    So, we can run Binary Search on both the sorted arrays, if the element is present then
    one of the binary searches will return a positive value(index).
*/


#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int a[], int low,int high, int search)
{
    int mid;
    while(low<=high)
    {
        mid = low + (high-low)/2;

        if(search == a[mid])
        {
            return mid;
        }
        else if(a[mid]>search)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    return -1;
}

int main()
{
    // Taking Inputs
    int n,search;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }  
    cin>>search;
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
    
    //Now, we know mid holds the minimum element.
    int p1 = BinarySearch(a,0,mid-1,search);
    int p2 = BinarySearch(a,mid,n-1,search);
    if(p1>0 and p2==-1)
    {
        cout<<p1<<endl;
    }
    else if(p2>0 and p1==-1)
    {
        cout<<p2<<endl;
    }
    return 0;
}

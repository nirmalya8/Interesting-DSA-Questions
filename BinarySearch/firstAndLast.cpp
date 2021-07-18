/*  
    Problem Statement: 
    Given a SORTED array with duplicate elements and a search element,
    find the first and last occurance of the search element.

    Input-Output:
    Eg. [2,4,10,10,10,18,20]
    Search Element: 10
    First Occurance: 2
    Last Occurance: 4

    Modifying Binary Search to find first occurance of search element:
    1. Setting of low, high and mid requires no modifications
    2. Set a variable first = -1, which will hold first index of the search element 
    3. The code for Binary Search remains the same, with only one slight modification:
            if the mid element is equal to the search element,
                store mid in first
                set high to mid-1 (As if there multiple occurances then the first occurance will occur before mid
                and if mid is the first occurance then it is already stored in the result)

    For the last occurance,if mid element is equal to the search element, store it in a variable and set low to mid+1

*/


#include<bits/stdc++.h>
using namespace std;

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

    // performing binary search for the first occurance of the search element
    int low = 0;
    int high = n-1;
    int mid; // low + (high-low)/2 = (low + high)/2
    int first = -1;

    while(low<=high)
    {
        mid = low + (high-low)/2;

        if(search == a[mid])
        {
            first = mid;
            high = mid-1;
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
    if (first == -1) //the search element is not present
    {
        cout<<"Search Not Found"<<endl;
        return 0;
    }

    // performing binary search for the first occurance of the search element
    low = 0;
    high = n-1;
    mid; // low + (high-low)/2 = (low + high)/2
    int last = -1;

    while(low<=high)
    {
        mid = low + (high-low)/2;

        if(search == a[mid])
        {
            last = mid;
            low = mid+1;
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

    cout<<first<<"  "<<last<<endl;
    return 0;
    
}

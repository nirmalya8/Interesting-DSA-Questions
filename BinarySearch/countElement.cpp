/*  
    Problem Statement: 
    Given a SORTED array and an element, find the number of times it occurs in the array. O(log N)

    Input-Output:
    Eg. [2,4,10,10,10,18,20]
    Element: 10
    Count: 3

    Modifying Binary Search to count the number of times the search element occurs:
    1. Setting of low, high and mid requires no modifications
    2. Set a variable first = -1, which will hold first index of the search element 
    3. The code for Binary Search remains the same, with only one slight modification:
            if the mid element is equal to the search element,
                set high to mid-1 (As if there multiple occurances then the first occurance will occur before mid
                and if mid is the first occurance then it is already stored in the result)
    4. Outside the loop set first <- mid

    For the last occurance,if mid element is equal to the search element, set low to mid+1. Outside the loop set last <- mid
    Count of the element will be last-first+1. 

*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Taking Inputs
    int n,element;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>element;

    // performing binary search for the first occurance of the search element
    int low = 0;
    int high = n-1;
    int mid; // low + (high-low)/2 = (low + high)/2
    int first = -1;

    while(low<=high)
    {
        mid = low + (high-low)/2;

        if(element == a[mid])
        {
            high = mid-1;
        }
        else if(a[mid]>element)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    first = mid;
    if (first == -1) //the search element is not present
    {
        cout<<"Search Not Found"<<endl;
        return 0;
    }

    // performing binary search for the last occurance of the search element
    low = 0;
    high = n-1;
    //mid =  low + (high-low)/2 = (low + high)/2
    int last = -1;

    while(low<=high)
    {
        mid = low + (high-low)/2;

        if(element == a[mid])
        {
            low = mid+1;
        }
        else if(a[mid]>element)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    last = mid;

    cout<<last-first+1<<endl;
    return 0;
    
}

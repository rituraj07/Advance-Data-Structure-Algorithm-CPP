#include<bits/stdc++.h>
using namespace std;
int partion(int arr[],int low,int high)
{
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
    
}

void qs(int a[],int si,int ei)
{
    if(si>=ei)
        return;
    int m=partion(a,si,ei);
    qs(a,si,m-1);
    qs(a,m+1,ei);
    return;
}

void quickSort(int a[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    
    qs(a,0,size-1);

}

//5 2 6 1 8 9
//0 1 2 3 4 5

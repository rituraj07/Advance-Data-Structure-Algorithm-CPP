void merge(int a[],int si,int m,int ei)
{
    int t[ei-si],k=0,i,j;
    for(i=si,j=m;i<m&&j<=ei;)
    {
        if(a[i]<=a[j])
        {
            t[k++]=a[i++];
        }
        else
        {
            t[k++]=a[j++];
        }
    }
    while(i<m)
        t[k++]=a[i++];
    while(j<=ei)
        t[k++]=a[j++];
    k=0;
    for(i=si;i<=ei;i++)
    {
        a[i]=t[k++];
    }
    return;
        
}
void ms(int a[],int si,int ei)
{
    if(si>=ei)
        return;
    int m=(si+ei)/2;
    ms(a,si,m);
    ms(a,m+1,ei);
    merge(a,si,m+1,ei);
    return;
}
void mergeSort(int a[], int size){
	// Write your code here
    ms(a,0,size-1);
    //for(int i=0;i<size;i++)
      //  cout<<a[i]<<" ";
        
}

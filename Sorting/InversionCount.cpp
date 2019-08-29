
long long merge(int a[],int l,int m,int r)
{
	int i=l,j=m,k=0,ivc=0;
	int t[100001];
	while(i<m && j<=r)
	{
		if(a[i]<=a[j])
		{
			t[k++]=a[i++];
		}
		else
		{
			t[k++]=a[j++];
			ivc+=m-i;
		}
	}
	while(i<m)
	t[k++]=a[i++];
	while(j<=r)
	t[k++]=a[j++];
    for(i=l,k=0;i<=r;i++,k++)
        a[i]=t[k];
	return ivc;
}

long long mergeSort(int arr[],int l,int r)
{
	long long ivc=0;
	
    if(r>l){
        int m=(l+r)/2;
	long long ivcl=mergeSort(arr,l,m);
	long long ivcr=mergeSort(arr,m+1,r);
	long long ivcm=merge(arr,l,m+1,r);
        return ivcl+ivcr+ivcm;
    }
	return 0;
}




long long solve(int arr[], int arr_size)
{
   
   return mergeSort(arr,0,arr_size-1); 
}
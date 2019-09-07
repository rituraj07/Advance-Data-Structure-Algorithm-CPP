int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int i=0,ans;
     int mn=100000;
    for(i=0;i<A.size()-2;i++)
    {
        int j=i+1;
        int k=A.size()-1;
        int t=B-A[i];
       
        while(j<k){
            //cout<<i<<" "<<j<<" "<<k<<endl;
        if(mn>abs(t-(A[j]+A[k])))
        {
            mn=abs(t-(A[j]+A[k]));
            ans=A[i]+A[j]+A[k];
        }
       // cout<<i<<" "<<j<<" "<<k<<" "<<ans<<endl;
        if(A[j]+A[k]>t)
        k--;
        else if(A[j]+A[k]<t)
        j++;
        else
        {
            ans=A[i]+A[j]+A[k];
            break;
        }
        }
    }
    return ans;
}

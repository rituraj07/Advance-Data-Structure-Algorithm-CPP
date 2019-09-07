int Solution::maxArea(vector<int> &A) {
    int i=0,j=A.size()-1,ans=0;
    while(i<j)
    {
        ans=max(ans,min(A[i],A[j])*(j-i));
        if(A[i]<A[j])
        i++;
        else
        j--;
    }
    return ans;
}
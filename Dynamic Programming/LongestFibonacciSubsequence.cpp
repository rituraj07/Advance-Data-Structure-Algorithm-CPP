class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
         unordered_map<int, int> ind;
        int n=A.size();
        for(int i=0;i<A.size();i++)
        {
            ind[A[i]]=i;
        }
        int ans=0;
        unordered_map<int,int> l;
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<k;j++)
            {
                if(A[k]-A[j]<A[j]&&ind.count(A[k]-A[j]))
                {
                    int i=ind[A[k]-A[j]];
                    l[j*n+k]=l[i*n+j]+1;
                    ans=max(ans,l[j*n+k]+2);
                }
            }
        }
        return ans>=3?ans:0;
    }
};
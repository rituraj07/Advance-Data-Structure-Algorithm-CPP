class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size(),b=0,i;
        for(i=n-1;i>0;i--)
        {
            if(a[i-1]<a[i])
            {
                i--;
                b=1;
                break;
            }
        }
        if(b)
        {
            sort(a.begin()+i+1,a.end());
            for(int j=i+1;j<n;j++)
            {
                if(a[j]>a[i])
                {
                    int t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                    break;
                }   
            }
            
        }
        else
        {
            sort(a.begin(),a.end());
        }
    }
};
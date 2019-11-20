class Solution {
public:
    string longestPalindrome(string a) {
        
        int n=a.length(),mx=INT_MIN,s,e;
        if(n==0)
            return "";
        if(n==1){
            string v;
            v+=a[0];
            return v;
        }
        for(int i=0;i<n;i++)
        {
            int ans=1,j=1;
            while(i-j>=0&&i+j<n&&a[i-j]==a[i+j])
            {
                ans+=2;
                j++;
            }
            if(ans>mx)
            {
                mx=ans;
                s=i-j;
                e=i+j;
            }
            if(i<n-1&&a[i]==a[i+1])
            {
                ans=2;
                j=1;
                while(i-j>=0&&i+j+1<n&&a[i-j]==a[i+j+1])
                {
                    ans+=2;
                    j++;
                }
                if(ans>mx)
                {
                    mx=ans;
                    s=i-j;
                    e=i+j+1;
                }
            }
        }
        //cout<<mx<<" "<<s<<" "<<e<<endl;
        string res;
        for(int i=s+1;i<e;i++)
            res+=a[i];
        return res;
    }
};
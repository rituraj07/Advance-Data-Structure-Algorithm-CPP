void fn(vector<string> &A,int i,int j)
{
    if(i<0||i>=A.size()||j<0||j>=A[0].length())
    return;
    if(A[i][j]!='X')
    return;
    A[i][j]='O';
    fn(A,i+1,j);
    fn(A,i,j+1);
    fn(A,i-1,j);
    fn(A,i,j-1);
}
int Solution::black(vector<string> &A) {
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].length();j++)
        {
            if(A[i][j]=='X')
            {
                fn(A,i,j);
                ans++;
            }
        }
    }
    return ans;
}

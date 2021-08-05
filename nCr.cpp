class Solution{
public:
    const int mod = 1e9+7;
    int nCr(int n, int r){
        // code here
        //0th row will represent the n-1Cr
        //1st row will store the nCr by calculating
        long long dp[2][r+1];
        dp[0][0]=1,dp[0][1]=1;
        for(int i=2;i<=r;++i) dp[0][i]=0;
        for(int i=2;i<=n;++i)
        {
            dp[1][0]=1,dp[1][1]=i;
            for(int j=2;j<=r;++j)
            {
                dp[1][j]=(dp[0][j]+dp[0][j-1])%mod;
            }
            for(int j=0;j<=r;++j) dp[0][j]=dp[1][j];
        }
        return dp[0][r];
    }
};

class Solution {
public:
    int countPrimes(int n) {
        //self
        if(n<=2) return 0;
        bool prime[n+1];
        memset(prime,true,sizeof(prime));
        prime[1]=false;
        for(int i=2;i*i<=n;++i)
        {
            if(prime[i])
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;++i) cnt+=prime[i];
        return cnt;
    }
};
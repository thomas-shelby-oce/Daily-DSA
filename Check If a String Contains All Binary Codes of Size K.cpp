class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //self
        if(k>=(int)s.length()) return false;
        int n = 1<<k;
        bool present[n];
        memset(present,false,sizeof(present));
        int curr=0;
        for(int i=0;i<k;++i)
        {
            curr=(2*curr)+s[i]-'0';
        }
        present[curr]=true;
        for(int i=k;i<(int)s.length();++i)
        {
            if(s[i-k]=='1') curr-=(1<<(k-1));
            curr=(2*curr)+s[i]-'0';
            present[curr]=true;
        }
        for(int i=0;i<n;++i) if(present[i]==false) return false;
        return true;
    }
};
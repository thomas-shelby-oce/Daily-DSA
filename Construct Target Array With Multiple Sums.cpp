class Solution {
public:
    bool isPossible(vector<int>& target) {
        //except mod part self
        // mod part from here https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/510256/JavaC%2B%2BPython-Backtrack-OJ-is-wrong
        if(target.size()==1)
        {
            if(target[0]==1) return true;
            return false;
        }
        priority_queue<int> pq;
        long long sum=0;
        for(int i:target)
        {
            sum+=i;
            pq.push(i);
        }
        while(pq.top()>1)
        {
            long long curr=pq.top();
            pq.pop();
            sum-=curr;
            if(sum==1) return true;
            if(curr-sum<0||curr%sum==0) return false;
            long long temp=curr%sum;
            pq.push(temp);
            sum+=temp;
        }
        return true;
    }
};
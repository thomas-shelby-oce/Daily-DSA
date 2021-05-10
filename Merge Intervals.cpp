bool cmp (vector<int> a, vector<int> b){
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //self
        sort(intervals.begin(),intervals.end(),cmp);
        if(intervals.size()==0) return {{}};
        int start=-1,end=-1;
        vector<vector<int>> res;
        for(vector<int> v:intervals)
        {
            if(v[0]>end)
            {
                if(end!=-1) res.push_back({start,end});
                start=v[0],end=v[1];
            }
            else
            {
                end=max(end,v[1]);
            }
        }
        res.push_back({start,end});
        return res;
    }
};
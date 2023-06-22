class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeintervals;
        if(intervals.size()==0){
            return intervals;
        }
        sort(intervals.begin() , intervals.end());
        vector<int>tempinterval = intervals[0];
        
        
        for(auto iterator: intervals){
            if(iterator[0]<=tempinterval[1]){
                tempinterval[1] = max(tempinterval[1] , iterator[1]);
            }
            else{
                mergeintervals.push_back(tempinterval);
                tempinterval = iterator;
            }
            
        }
        mergeintervals.push_back(tempinterval);
        return mergeintervals;
        
    }
};
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted;
        for(int i : nums){
            sorted.push_back(i);
        }
        sort(sorted.begin(), sorted.end());
        int start = sorted.size(), end = 0;
        for(int i = 0; i < sorted.size(); ++i){
            if(sorted[i] != nums[i]){
                start = min(i, start);
                end = max(i, end);
            }
        }
        return max(0, (end-start)+1);
    }
};
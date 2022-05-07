class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //nums[i] and mini
        stack<pair<int, int>> check;
        int mini = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            while(!check.empty() && check.top().first <= nums[i]){
                check.pop();
            }
            if(!check.empty() && nums[i] < check.top().first && nums[i] > check.top().second){
                return true;
            }
            check.push({nums[i], mini});
            mini = min(mini, nums[i]);
        }
        return false;
    }
};
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0, end = nums.size()-1, cnt = 0, n_start = 0, n_end = nums.size()-1;
        vector<int> ans(nums.size(), 0);
        while(cnt < nums.size()){
            if(nums[start]%2 == 0){
                ans[n_start] = nums[start];
                ++start;
                ++n_start;
                ++cnt;
            }else if(nums[start]%2 != 0){
                ans[n_end] = nums[start];
                ++start;
                --n_end;
                ++cnt;
            }else if(nums[end]%2 == 0){
                ans[n_start] = nums[end];
                --end;
                ++n_start;
                ++cnt;
            }else{
                ans[n_end] = nums[end];
                --end;
                --n_end;
                ++cnt;
            }
        }
        return ans;
    }
};
class Solution {
private:
    void BackTracking(vector<int>& nums,vector<vector<int>> &ans,vector<int> tmp){
        if(tmp.size()==nums.size()){
            ans.push_back(tmp);
            return ;
        }
        
        for(int j=0; j<nums.size(); ++j){
            if(nums[j]!=11){
			
                if(j>0 && nums[j]==nums[j-1]) continue; 

                int i=nums[j];
                nums[j]=11;
                tmp.push_back(i);
                BackTracking(nums,ans,tmp);
                tmp.pop_back();
                nums[j]=i;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        vector<vector<int>> ans;
        BackTracking(nums,ans,{});
        return ans;
    }
};
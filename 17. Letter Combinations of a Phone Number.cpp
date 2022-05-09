class Solution {
public:
    
    vector<string> ans;
    map<int, string> nums;
    
    void backTraking(int i, string cur, string digits){
            if(cur.length() == digits.length()){
                ans.push_back(cur);
                return;
            }
            for(int j = 0; j < nums[digits[i]-'0'].length(); ++j){
                backTraking(i+1, cur+ nums[digits[i]-'0'][j], digits);
            }
    }
    
    vector<string> letterCombinations(string digits) {
        nums[2] = "abc";
        nums[3] = "def";
        nums[4] = "ghi";
        nums[5] = "jkl";
        nums[6] = "mno";
        nums[7] = "pqrs";
        nums[8] = "tuv";
        nums[9] = "wxyz";
        
        if(digits.length() > 0) backTraking(0, "", digits);
        
        return ans;
    }
};
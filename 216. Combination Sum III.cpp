class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    
    void BackTracking(int start, int k, int n){
        if(k < 0 || n < 0) return;
        if(k == 0 && n == 0){
            ans.push_back(tmp);
            return;
        }
            
        for(int i = start; i <= 9; ++i){
            tmp.push_back(i);
            BackTracking(i + 1, k - 1, n - i);
            if(tmp.size() > 0) tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        BackTracking(1, k, n);
        return ans;
    }
};
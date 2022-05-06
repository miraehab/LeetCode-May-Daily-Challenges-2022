class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map <int, int> freq;
        for(auto &i : nums){
            if(freq[k - i]){
                ans++;
                freq[k - i]--;
            }
            else freq[i]++;
        }
        return ans;
    }
};
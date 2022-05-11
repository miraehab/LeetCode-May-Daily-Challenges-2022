class Solution {
public:
    string tmp;
    vector<char> chars = {'a','e','i','o','u'};
    int cnt = 0;
    void BackTracking(int start, int n){
        if(n == 0){
            ++cnt;
            return;
        }
            
        for(int i = start; i < 5; ++i){
            tmp += chars[i];
            BackTracking(i , n-1);
            if(tmp.length() > 0) tmp.pop_back();
        }
    }
    
    int countVowelStrings(int n) {
        BackTracking(0, n);
        return cnt;
    }
};
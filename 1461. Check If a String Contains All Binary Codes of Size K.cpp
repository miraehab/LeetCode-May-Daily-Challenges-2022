class Solution {
public:
    bool hasAllCodes(string s, int k) {
	
        if(k > s.size()) return false;

        set<string> subs;

        for(int i = 0; i <= s.size()-k; ++i)
            subs.insert(s.substr(i,k));

        return subs.size() == pow(2,k);
    }
};
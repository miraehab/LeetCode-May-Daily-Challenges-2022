class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string new_s, new_t;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] != '#'){
                new_s += s[i];
            }else{
                if(new_s.length() > 0) new_s.erase(new_s.end()-1);
            }
        }
        for(int i = 0; i < t.length(); ++i){
            if(t[i] != '#'){
                new_t += t[i];
            }else{
                if(new_t.length() > 0) new_t.erase(new_t.end()-1);
            }
        }
        if(new_s == new_t) return true;
        else return false;
    }
};
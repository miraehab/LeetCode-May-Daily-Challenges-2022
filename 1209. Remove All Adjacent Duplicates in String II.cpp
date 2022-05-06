class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, short>> st;
          string ans;
          for (auto ch : s) {
            if (st.empty() || st.back().first != ch) st.push_back({ ch, 0 });
            if (++st.back().second == k) st.pop_back();
          }
          for (auto& p : st) ans += string(p.second, p.first);
          return ans;
    }
};
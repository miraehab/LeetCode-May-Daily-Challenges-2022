class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxi = 0;
        for(int i = 0; i < s.size(); ++i){
            int t = stk.top();
            if(t!=-1&&s[i]==')'&&s[t]=='('){
                stk.pop();
                maxi = max(maxi,i-stk.top());
            }
            else{
                stk.push(i);
            }
        }
        return maxi;
    }
};
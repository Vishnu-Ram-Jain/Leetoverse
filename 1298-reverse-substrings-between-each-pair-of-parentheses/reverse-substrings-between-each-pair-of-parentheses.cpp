class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(auto &i : s){
            if(i == '('){
                st.push(i);
            }
            else if(i == ')'){
                queue<char> temp;
                while(st.top() != '('){
                    temp.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!temp.empty()){
                    st.push(temp.front());
                    temp.pop();
                }
            }
            else{
                st.push(i);
            }
        }

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
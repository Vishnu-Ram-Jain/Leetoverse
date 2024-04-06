class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push({s[i],i});
            }
            // koi closing bracket hai ya alphabet h;
            else{
                if(s[i] == ')'){
                    if(!st.empty() && st.top().first == '('){
                        st.pop();
                    }
                    else{
                        st.push({s[i],i});
                    }
                }
            }
        }
        unordered_map<int,bool> mp;
        while(!st.empty()){
            int ind = st.top().second;
            mp[ind] = 1;
            st.pop();
        }
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(mp.find(i) != mp.end())continue;
            ans += s[i];
        }
        return ans;
    }
};
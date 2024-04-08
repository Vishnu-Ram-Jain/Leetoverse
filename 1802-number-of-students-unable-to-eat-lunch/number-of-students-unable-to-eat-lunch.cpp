class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;
        int n = students.size();
        for(int i=n-1;i>=0;i--){
            st.push(sandwiches[i]);
        }
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int cnt = n*n;
        while(cnt--){
            if(q.size() == 0)return 0;
            if(q.front() == st.top()){
               q.pop();
               st.pop();
            }
            else{
                int x = q.front();
                q.pop();
                q.push(x);
            }
        }
        cnt = 0;
        while(!q.empty()){
            cnt++;
            q.pop();
        }
        return cnt;
    }
};
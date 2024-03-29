class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {

        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            int count = 0;
            int row = startPos[0];
            int col = startPos[1];
            for(int j=i;j<s.size();j++)
            {
                if(s[j]=='L') col--;
                if(s[j]=='R') col++;
                if(s[j]=='D') row++;
                if(s[j]=='U') row--;

                if(col<0 || row<0 || col>=n || row>=n)
                    break;
                else
                    count++;
            }
            ans.push_back(count);

        }
        return ans;
    }
};
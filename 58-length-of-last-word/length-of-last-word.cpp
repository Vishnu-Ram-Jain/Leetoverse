class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        // s=s.trim();
        int i=0;
        int count=0;

        for(int i=n-1;i>=0;i--){
            if(s[i] != ' '){
                count++;
            }
            else{
                if(count == 0){
                    continue;
                }
                else{
                    return count;
                }
            }

        }
        return count;
    }
};
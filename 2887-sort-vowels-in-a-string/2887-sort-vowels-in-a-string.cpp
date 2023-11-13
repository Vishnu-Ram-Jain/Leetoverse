class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        string t;
        vector<int> vowel;
        for(int i=0;i<n;i++){
            t.push_back('#');
        }
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == 'a'|| ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u'|| 
              ch == 'A'|| ch == 'E'|| ch == 'I'|| ch == 'O'|| ch == 'U'){
                vowel.push_back(ch);
            }
            else{
                t[i] = s[i];
            }
        }
        
        sort(vowel.begin(),vowel.end());
        queue<char> q;
        for(int i=0;i<vowel.size();i++){
            char ch = vowel[i];
            q.push(ch);
        }
        
        for(int i=0;i<n;i++){
            if(t[i] == '#'){
                t[i] = q.front();
                q.pop();
            }
        }
        
        return t;
        
    }
};
struct Node {
    Node* links[26];
    bool flag = false;

    bool containskey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool solve(Node* root, string word, int ind){
        if(ind == word.size() && root->isEnd() == true)return true;
        if(ind == word.size() && root->isEnd() == false)return false;

        if(word[ind] == '.'){
            for(int i=0;i<26;i++){
                if(root->get(i+'a') != NULL){
                    if(solve(root->get(i+'a'),word,ind+1))return true;
                }
            }
            return false;
        }
        else{
            if(root->links[word[ind] - 'a'] == NULL)return false;
            return solve(root->get(word[ind]),word,ind+1);
        }
    }
    bool search(string word) {
        Node* node = root;
        return solve(node,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
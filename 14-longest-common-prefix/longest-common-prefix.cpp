#include <bits/stdc++.h> 

using namespace std;


struct Node {

    Node* links[26];

    int cntEndWith = 0;

    int cntPrefix = 0; 

    bool containsKey(char ch) {
     
        return (links[ch - 'a'] != NULL); 
    }

    Node* get(char ch) {
   
        return links[ch - 'a']; 
    }

    void put(char ch, Node* node) {
 
        links[ch - 'a'] = node;
    }


    void increaseEnd() {
        cntEndWith++; 
    }


    void increasePrefix() {
        cntPrefix++;
    }

   
    void deleteEnd() {
        cntEndWith--; 
    }


    void reducePrefix() {
        cntPrefix--; 
    }

    int getcount(){
        return cntPrefix;
    }
};

class Trie {
private:

    Node* root; 

public:

    Trie() {
        root = new Node(); 
    }


    void insert(string word) {
        Node* node = root; 

        for (int i = 0; i < word.size(); i++) { 
  
            if (!node->containsKey(word[i])) {
     
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]);
            node->increasePrefix(); 
        }
        node->increaseEnd(); 
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            if (node->containsKey(word[i])) { 
                node = node->get(word[i]); 
            } else {
                return 0;
            }
        }
        return node->cntEndWith; 
    }

    int countWordsStartingWith(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            if (node->containsKey(word[i])) { 
                node = node->get(word[i]); 
            } else {
                return 0; 
            }
        }
        return node->cntPrefix; 
    }

    void erase(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) { 
            if (node->containsKey(word[i])) { 
                node = node->get(word[i]);
                node->reducePrefix(); 
            } else {
                return; 
            }
        }
        node->deleteEnd(); 
    }
    string get_maxString(string &word, int n){
        Node* node = root;
        string ans = "";
        int cnt = 0;
        for(int i=0;i<word.size();i++){
            node = node->get(word[i]);
            if(node->getcount() != n)return ans;
            ans += word[i];
            // cout<<node->getcount()<<" ";
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n = arr.size();
        int mini = INT_MAX;
        string t ;
        Trie trie;
        for(auto &it : arr){
            if(it.size() < mini){
                mini = it.size();
                t = it;
            }
            trie.insert(it);
        }
        // cout<<t<<endl;
        return trie.get_maxString(t,n);
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        if(root->left==NULL and root->right==NULL){
            root->next = NULL;
            return root;
        }
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<Node*> lvl;
            for(int i=0;i<size;i++){
                Node* nod = q.front();
                q.pop();
                lvl.push_back(nod);
                if(nod->left!=NULL)q.push(nod->left);
                if(nod->right!=NULL)q.push(nod->right);
            }
            if(lvl.size()==1)lvl[0]->next=NULL;
            else{
                Node* nod = lvl[0];
                for(int i=1;i<lvl.size();i++){
                    nod->next = lvl[i];
                    nod = lvl[i];
                }
                nod->next = NULL;
            }
        }
        return root;
    }
};
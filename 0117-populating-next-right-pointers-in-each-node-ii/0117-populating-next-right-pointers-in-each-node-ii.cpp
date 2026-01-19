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
        if (root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            int x= q.size();
            Node *prev=NULL;
            for (int i =0;i<x;i++){
                Node *ft=q.front();
                if (i==0){
                    ft->next=NULL;
                    prev=ft;
                }
                else {
                    ft->next=prev;
                    prev=ft;
                }
                q.pop();
                if (ft->right!=NULL)q.push(ft->right); 
                if (ft->left!=NULL)q.push(ft->left);
            }
        }
        return root;
    }
};
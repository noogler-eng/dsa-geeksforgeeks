// pre order iterative trevarsal
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// taking an stack LIFO based
vector<int> PreOrderTraversal(Node* root){
    stack<Node*> s;
    vector<int> ans;
    if(root == NULL) return ans;
    
    s.push(root);
    while(!s.empty()){
        Node* node = s.top();
        s.pop();

        ans.push_back(node->data);
        // taking riight as first because who comes first will be deal last
        if(node->right != NULL) s.push(node->right);
    
        // it will be on the top
        if(node->left != NULL) s.push(node->left);
    }
    return ans;
}

int main(){
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> ans = PreOrderTraversal(root);
    // output: 1 2 3 4 5 6 7
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}
// binary tree border traversal in reverse order
#include<iostream>
#include<vector>
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

bool isLeaf(Node* root){
    if(root->right == NULL && root->left == NULL) return true;
    return false;
}

void rightNodeTraversal(Node* root, vector<int> &ans){
    Node* curr = NULL;
    if(root->right) curr = root->right;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
}

void leafNodeTraversal(Node* root, vector<int> &ans){
    if(isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }

    leafNodeTraversal(root->right, ans);
    leafNodeTraversal(root->left, ans);
}

void leftNodeTraversal(Node* root, vector<int> &ans){
    Node* curr = NULL;
    if(root->left) curr = root->left;
    vector<int> temp;

    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }

    // reversing the temporary vector
    for(int i=temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }
}

void print(vector<int> ans){
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return;
}   

void binaryTreeTraversal(Node* root){
    vector<int> ans;
    
    ans.push_back(root->data);
    rightNodeTraversal(root, ans);
    leafNodeTraversal(root, ans);
    leftNodeTraversal(root, ans);

    print(ans);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    binaryTreeTraversal(root);
    return 0;
}
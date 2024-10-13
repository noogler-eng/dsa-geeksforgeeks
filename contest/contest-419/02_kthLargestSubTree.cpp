// Kth largest subtree size in binary tree
#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node* right;
        Node* left;
        
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// this is challenge
bool checkPerfect(Node* root, int depth, int& leafLevel) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) {
        if (leafLevel == -1) {
            leafLevel = depth;
        }
        return (depth == leafLevel);
    }

    if (root->left == NULL || root->right == NULL) return false;
    return checkPerfect(root->left, depth + 1, leafLevel) && 
           checkPerfect(root->right, depth + 1, leafLevel);
}

bool isPerfect(Node* root){
    int leafLevel = -1;
    return checkPerfect(root, 0, leafLevel);
}

int noOfNodes(Node* root){
    if(root == NULL) return 0;

    return noOfNodes(root->left) + noOfNodes(root->right) + 1;
}

// perfect binary tree -> when all the leaf nodes are at same level
void kthLargestSubtree(Node* root, vector<int> &ans){
    if(root == NULL) return;

    if(isPerfect(root)){
        // no of nodes that perfect bianry tree
        int nodesNo = noOfNodes(root);
        ans.push_back(nodesNo);
    }
    kthLargestSubtree(root->left, ans);
    kthLargestSubtree(root->right, ans);
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(2);
    root->left->left->left = new Node(1);
    root->left->left->right = new Node(8);

    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    root->right->left->left = new Node(5);
    root->right->left->right = new Node(5);

    int k = 2;

    vector<int> ans;
    kthLargestSubtree(root, ans);
    sort(ans.begin(), ans.end());

    if (k > 0 && k <= ans.size()) {
        cout << "The " << k << "th largest subtree size is: " << ans[ans.size() - k] << endl;
    } else {
        cout << "Invalid value of K" << endl;
    }

    for(int it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
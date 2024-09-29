// right and left side view of the binary tree
// right side view node is that there can be any vertical but the horizontal must be the last one
// last node of every level 
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

// BFS traversal - it takes time complexity is o(n) and space complexity is o(all nodes)
// recursive solution - it takes time complexity is o(n) and space is o(n)

// traversing in different way so that every level first node is visible
// reverse preorder -> (root left right) - (right, left, root)
void traversal(Node* root, int level, vector<int> &ans){
    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root->data);

    traversal(root->right, level+1, ans);
    traversal(root->left, level+1, ans);
}

void print(vector<int> ans){
    for(int i: ans){
        cout<<i<<" ";
    }
    return;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans;
    traversal(root, 0, ans);

    print(ans);
    return 0;
}
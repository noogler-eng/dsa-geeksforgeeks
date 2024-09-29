// boundry traversal of binary tree
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
    if(root->left == NULL && root->right == NULL) return true;
    return false;
}

// here we traversed clockwise
// left traversal(excluding leaf) + leaf node + right traversal(excluding leaf, reverse) 
// all over time complexity is o(n)
void addLeftBoundary(Node* root, vector<int> &ans){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeafNode(Node* root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    addLeafNode(root->left, ans);
    addLeafNode(root->right, ans);
}

void addRightBoundary(Node* root, vector<int> &ans){
    Node* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    // adding the right one in reverse order
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

void boundaryTraversal(Node* root){
    vector<int> ans;
    ans.push_back(root->data);
    addLeftBoundary(root, ans);
    addLeafNode(root, ans);
    addRightBoundary(root, ans);

    print(ans);
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

    boundaryTraversal(root);
}

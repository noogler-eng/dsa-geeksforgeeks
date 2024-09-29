// Root to node path
// in order traversal has been used here

// important and confusing question

// time-complexity is o(n)
// space-complexity is o(h)

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

bool rootToNodePath(Node* root, int x, vector<int> &arr){
    if(root == NULL) return false;
    
    arr.push_back(root->data);
    if(root->data == x) return true;

    // now going to its left and right side if element is found there, if not returning false
    if(rootToNodePath(root->left, x, arr) || rootToNodePath(root->right, x, arr)) return true;

    // if the element is not found then returning false and pop
    arr.pop_back();
    return false;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    int key = 7;
    vector<int> ans;
    rootToNodePath(root, key, ans);
    
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
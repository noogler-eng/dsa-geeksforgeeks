// top view of the binary tree
// for the top view of any tree we can only see the left and right side

// time complexity is o(n)
// space complexity is o(2 * n)
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
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

// we can't using recurssion, so that's why we use level wise traversal
// we dont need any level here
vector<int> topView(Node* root){
    vector<int> ans;

    if(root == NULL) return ans;
    // Use map instead of unordered_map to maintain sorted order
    map<int, int> m;
    queue<pair<Node*, int>> q;

    // pusinh Node, and vertical
    q.push({root, 0});
    while(!q.empty()){
        Node* temp = q.front().first;
        int vertical = q.front().second;
        q.pop();

        // inserting element to map
        // if i exists then we dont have to again change its value
        // if the i is not exists then this will hold
        if(m.find(vertical) == m.end()) m[vertical] = temp->data;

        if(temp->left != NULL) q.push({temp->left, vertical-1});
        if(temp->right != NULL) q.push({temp->right, vertical+1});
    }

    for(auto i: m){
        ans.push_back(i.second);
    }
    return ans;
}

void print(vector<int> ans){
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
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

    vector<int> ans = topView(root);
    print(ans);
    return 0;
}
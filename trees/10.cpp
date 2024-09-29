// vertical order traversal of a binary tree

#include<iostream>
#include<bits/stdc++.h>
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

// travsersing vertical
//          1
//      2       3
//  4      5|6      7
// output: 
// 4
// 2
// 1, 5, 6
// 3
// 7

// stroing node, level and vertical in vector
// vertical, level, nodes
// map<int, map<int, vector<int>>> m;

// on moving to left reduce the vertical 
// on moving to right increase the verticle
vector<vector<int>> verticalOrderTraversal(Node* root){
    queue<pair<Node*, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> st;
    vector<vector<int>> ans;

    if(root == NULL) return ans;
    
    q.push({root ,{0, 0}});

    while(!q.empty()){
        Node* temp = q.front().first;
        int level = q.front().second.second;
        int vertical = q.front().second.first;
        q.pop();
        
        st[vertical][level].insert(temp->data);
        if(temp->left!=NULL) q.push({temp->left, {vertical - 1, level + 1}});
        if(temp->right!=NULL) q.push({temp->right, {vertical + 1, level + 1}});
    }

    for(auto i: st){
        vector<int> a;
        for(auto j: i.second){
            a.insert(a.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(a);
    }

    return ans;
}

void print(vector<vector<int>> ans){
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> ans = verticalOrderTraversal(root);
    print(ans);
    return 0;
}
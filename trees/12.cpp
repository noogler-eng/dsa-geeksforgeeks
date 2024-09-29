// bottom view of the binry tree
// here only the leaf node is not answer
// answer may contains the non leaf nodes also
//          1
//      2       3
// 4        5       7
//      8       9

// output: 4, 8, 5, 9, 7
#include<iostream>
#include<queue>
#include<map>
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

vector<int> bottomView(Node* root){

    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> m;
    queue<pair<Node*, int>> q;

    q.push({root, 0});
    while(!q.empty()){

        Node* temp = q.front().first;
        int verticle = q.front().second;
        q.pop();

        m[verticle] = temp->data;

        if(temp->left!= NULL) q.push({temp->left, verticle - 1});
        if(temp->right!= NULL) q.push({temp->right, verticle + 1});
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

    vector<int> ans = bottomView(root);
    print(ans);
    return 0;
}
// level order traversal
#include<iostream>
using namespace std;

#include<iostream>
#include<queue>
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


// simply we are making ab vector to store all the elements of same level and pushing it back
// into the main vector
vector<vector<int>> levelOrderTraversal(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> new_v;

        for(int i=0; i<size; i++){
            Node* node = q.front();
            q.pop();

            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            new_v.push_back(node->data);
        }
        ans.push_back(new_v);
    }
    return ans;
}

int main(){
    // making of binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<vector<int>> ans = levelOrderTraversal(root);
    // printing the nested vectors
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
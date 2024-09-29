// tree traversal 
// it is mostly done by BFS and DFS
// BFS - breadth first search
// DFS - depth first search

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

// here we checking the nearby elements
void BFS(Node* root){

    if(root == NULL) return;
    queue<Node*> q;

    Node* temp = root;
    q.push(temp);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node == NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
            continue;
        }

        cout<<node->data<<" ";
        if(node->left!=NULL) q.push(node->left);
        if(node->right!=NULL) q.push(node->right);
    }
}

// here we are moving to downside first
// this contains three types of traversal techniques
// Inorder traversal - left root right
// postorder traversal - left right root
// pre order traversal - root left right
void Inorder(Node* root){
    // inroder traversal
    if(root == NULL) return;
    
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(Node* root){
    // preoder traversal
    if(root == NULL) return;
    
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node* root){
    // postorder traversal
    if(root == NULL) return;
    
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
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
    
    BFS(root);
    
    // this below all are DFS techniques
    cout<<" -- -- "<<endl;
    Inorder(root);
    cout<<" -- -- "<<endl;
    Preorder(root);
    cout<<" -- -- "<<endl;
    Postorder(root);
    return 0;
}
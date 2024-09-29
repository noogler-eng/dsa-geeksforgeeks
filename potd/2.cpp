#include<iostream>
using namespace std;

// inplementation of doubly linkedlist with inroder traversal of the tree (binary)
// structure of Node of doubly linkedlist
class Node{
    public:
        int data;
        Node *next;
        Node *prev;
    
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
}; 

// structure of Node of binary tree
class TreeNode{
    public:    
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// inserting
// making prev to point new one
// new_one's prev = to joined one
void insertToDoubly(Node* &tail, int data){
    Node* new_node = new Node(data);
    
    tail->next = new_node;
    new_node->prev = tail;

    tail = tail->next;
}

// inserting every element in the doubly linkedlist according to inorder traversal
void inOrdertraversal(Node* &tail, TreeNode* &root){
    if(root == NULL) return ;

    inOrdertraversal(tail, root->left);
    insertToDoubly(tail, root->data);
    inOrdertraversal(tail, root->right);
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){  
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}

Node* makingDoublyFromBt(){

    // making an binary tree
    // joining with left and right
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(12);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(25);
    root->left->right = new TreeNode(30);
    root->right->left = new TreeNode(36);

    // tail is required as connecting with tail
    Node* head = new Node(0);
    Node* tail = head;
    inOrdertraversal(tail, root);
    head = head->next;
    head->prev = NULL;
    print(head);
    return head;
}

int main(){
    makingDoublyFromBt();
    return 0;
}


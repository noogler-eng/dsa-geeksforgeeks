// Lowest common ancestor 
// here we have to find the common ancestor of given two nodes as the common from their path
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
void getPathToNode(Node* root, int x, vector<int> &path){
    if(root == NULL) return false;

}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->right->right = new Node(9);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> path_1;
    vector<int> path_2;
    getPathToNode(root, 4, path_1);
    getPathToNode(root, 4, path_2);

    int i=0;
    while(i < path_1.size() && i < path_2.size() ){
        if(path_1[i] == path_2[i]) {
            cout<<"lowest common path -> ",path_1[i]<<endl;
            break;
        }
        i++;
    }

    return 0;
}
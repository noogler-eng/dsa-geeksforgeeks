// reverse nodes in k group 
#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next = NULL;
        Node(int data){
            this->data = data;
        }
};

void Reverse(Node* head, int k){

}

void reverseKNodes(Node* &head, int k){

    // 1. finding the first group of size k
    // 2. reversing the group and preserving the future linkedlist
    // 3. connect with the reserver one 

    Node* temp = head;
    




}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);
    int rev = 3;

    // linkedlist = 1->2->3->4->5->6->7->8->9->10
    // after reverse in k group = 3->2->1->6->5->4->9->8->7->10
    reverseKNodes(head, rev);
    print(head);
    return 0;
}
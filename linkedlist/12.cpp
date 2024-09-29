// finding the middle of the given linkedlist
#include<iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

int middleNodeData(Node* head){
    // time complexity is o(n)
    if(head == NULL) return -1;
    if(head->next == NULL) return head->data;

    Node* slow = head;
    Node* fast = head;
    // always check the conditions here as point of standing 
    while(fast!= NULL && slow!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int ans = middleNodeData(head); 
    cout<<ans<<endl;
    return 0;
}
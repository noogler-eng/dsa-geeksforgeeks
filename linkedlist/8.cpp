// adding 1 to linkedlist
// 1 -> 5 -> 9 + 1 = 1 -> 6 -> 0
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

Node* reverseLinkedlist(Node* head){
    Node* temp = head;
    Node* res = NULL;
    Node* prev = NULL;
    while(temp != NULL){
        res = temp->next;
        temp->next = prev;
        prev = temp;
        temp = res;
    }
    
    return prev;
}

// time compleity is o(3n) => o(n)
// space compexlity is o(n)
void addNumberToLinkedList(Node* &head, int x){
    // reversing an linkedlist
    head = reverseLinkedlist(head);
    
    // we getting the our node as prev; 
    // from there we have to add x
    Node* prev = head;

    // this is the main step to take the initial value as x 
    int carry = x;

    int sum = 0;
    while(prev!=NULL && carry > 0){
        sum = prev->data + carry;
        prev->data = sum % 10;
        carry = sum / 10;

        if(prev->next == NULL && carry > 0){
            prev->next = new Node(carry);
            carry = 0;
        }

        prev = prev->next;
    }

    head = reverseLinkedlist(head);
    return;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(9);
    int x = 1;

    print(head);
    addNumberToLinkedList(head, x);
    cout<<endl;
    print(head);
    return 0;
}
// adding 1 to the linkedlist using recurssion
// time complexity is o(n)
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

int recursvieAdd(Node* &head, int x){
    if(head == NULL) return x;
    int carry = recursvieAdd(head->next, x);
    // here we are usign backtracking
    int sum = carry + head->data;
    head->data = sum % 10;
    carry = sum / 10;  
    return carry;
}

void recursive(Node* &head, int x){
    
    int carry = recursvieAdd(head, x);
    if(carry > 0){
        Node* newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }
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
    recursive(head, x);
    print(head);
    return 0;
}
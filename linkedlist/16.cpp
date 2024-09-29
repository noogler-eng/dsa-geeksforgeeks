// delete the middle node of the linkedlist
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
void print(Node* head){
    Node* temp = head;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

void deleteMiddleNode(Node* &head){
    
    // 1 -> 2 -> 3 -> 4 -> 5
    // s f , here fast will end up at null, slow remain same

    if(head == NULL || head->next == NULL) return; 
    
    Node* slow = head;
    Node* fast = head->next;
    Node* prev = NULL;

    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // do it in copy you will understand
    // main factor is here if the fast will end on null or not
    if(fast != NULL) {
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    slow->next = NULL;
    delete(slow);
    return;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    print(head);
    deleteMiddleNode(head); 
    print(head);
    return 0;
}
// delete all the occourence of key in the doubly linekd list
#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;    
        Node* prev;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};
Node* DLLDeleteKey(Node* &head, int x){

    if(head == NULL || (head->next == NULL && head->data != x)) return NULL;
    if(head->next == NULL && head->data != x) return head;

    Node* temp = head;
    while(temp!=NULL){
        // dealing with the fist node
        if(temp->data == x && temp->prev == NULL){
            head = temp->next;
            temp = temp->next;
            temp->prev = NULL;
        }else if(temp->data == x && temp->next == NULL){
            temp = temp->prev;
            temp->next = NULL;
            return head;
        }else if(temp->data == x){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp = temp->next;
        }else{
            temp = temp->next;
        }  
    }
    return head;
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

    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->prev = head;
    int x = 10;

    print(head);
    DLLDeleteKey(head, x);
    print(head);
    return 0;
}


// this is the right way of doing this ...
void deleteAllOccurOfX(struct Node** head, int x) {
        Node* temp = *head;
        
        if(temp == NULL) {
            return;
        }

        while(temp!=NULL){
            // dealing with the fist node
            if(temp->data == x && temp->prev == NULL){
                *head = temp->next;
                temp = temp->next;
                temp->prev = NULL;
            }else if(temp->data == x && temp->next == NULL){
                temp = temp->prev;
                temp->next = NULL;
                return;
            }else if(temp->data == x){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp = temp->next;
            }else{
                temp = temp->next;
            }  
        }
        return;
    }
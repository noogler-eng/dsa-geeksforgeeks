// find the length of the loop
#include<iostream>
#include<unordered_map>
#include<map>
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

// first common
int LoopLength(Node* head){

    // 1. detect the loop
    // 2. when loop is detectd then again count
    
    if(head == NULL || head->next == NULL) return 0;

    Node* slow = head;
    Node* fast = head->next;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        // loop detected!!
        if(slow == fast){
            int len = 1;
            // here we cant so temp != slow
            // as we initlizing the temp = slow
            // so why we increase length by 1 already
            Node* temp = slow->next;
            while(temp!=slow){
                len++;
                temp = temp->next;
            }
            return len;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return 0;
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
    head->next->next->next->next->next->next->next->next->next = head->next->next;

    int lengthLoop = LoopLength(head);
    cout<<lengthLoop<<endl;
    return 0;
}
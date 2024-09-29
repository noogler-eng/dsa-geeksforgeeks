// finding the starting point of the loop in any linkedlist
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

// time compelxity is o(n)
// space complexity is o(1)
Node* loopPointDetect(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        // this will be comes first as both starting linewaise
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }  
    }

    // 2. in case there is no loop
    return NULL;
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

    Node* ans = loopPointDetect(head);
    if(ans!=NULL){
        cout<<ans->data<<endl;
    }else{
        cout<<"no loop"<<endl;
    }
    return 0;
}
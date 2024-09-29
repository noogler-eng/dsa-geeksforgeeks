// Detect a loop or cycyle in the linkedlist
#include<iostream>
#include<unordered_map>
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

// using hashmap
bool isLoop(Node* head){
    Node* temp = head;
    unordered_map<Node* ,int> m;

    while(temp!=NULL){
        if(m.find(temp)!=m.end()){
            return true;
        }else{
            m[temp] = 1;
        }
        temp = temp->next;
    }

    return false;
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
    head->next->next->next->next->next->next->next->next->next = head->next->next->next;

    bool isLoopPresent = isLoop(head);
    cout<<isLoop<<endl;
    return 0;
}
// Clone a linked list with next and random pointer
// hard level important question

#include<iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node* next;
        Node* random;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }
};

class Solution {
  public:
    Node *copyList(Node *head) {
        Node* temp = head;
        
        if(head == NULL) return head;

        // 2 -> 3 -> 1 -> 4
        // time complexity is o(n)
        while(temp!=NULL){
            Node* newNode = new Node(temp->data);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        // 2 -> 2 -> 3 -> 3 -> 1 -> 1 -> 4 -> 4
        while(temp!=NULL){
            if(temp->random!=NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
    
        // now removing the original elements and making its sperate original head
        Node* newHead = head->next;
        Node* ori = head;
        Node* local = head->next;
        while(ori!=NULL){
            ori->next = local->next;
            ori = ori->next;
            
            if(ori!=NULL){
                local-> next = ori->next;
                local = local->next;
            }else{
                local->next = NULL;
            }
        }
        
        return newHead;
    }
};
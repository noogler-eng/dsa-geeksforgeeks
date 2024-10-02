// remove duplicated from DLL
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

class Solution
{
public:

    Node* removeDuplicates(struct Node *head)
    {
       if(head == NULL || head->next == NULL) return head;

        Node* temp = head;
        Node* start = temp;
        while(temp->next!=NULL){
            // removing this next node
            if(temp->data == temp->next->data){
                if(temp->next->next == NULL){
                    temp->next = NULL;
                    return start;
                }
                temp->next->next->prev = temp;
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
        }
        return start;
    }
};
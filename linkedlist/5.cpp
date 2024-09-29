// middle element of the linked lsit
// can be solved by two approach - 
// length of linked list by o(n) then middle element by o(n/2)
// by two pointer approach moving first pointer by 2 and another pointer by 1 tc -> o(n)/2;

#include<iostream>
using namespace std;

// this is how node strcut is defined
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    // input 17 6 10 10 8 5 15 7 1
    // f -> 17, 6, 10, 10, 8
    // s -> 17, 10, 8, 15, 1
    // output 8
    
    // input 20 15 2 13 2 10 13 3 2 6
    // f -> 20, 15, 2, 13, 2, 10
    // s -> 20, 2, 2, 13, 2, NULL
    // output 
    
    // input 1, 2, 3, 4, 5
    // f -> 1, 2, 3
    // s -> 1, 3, 5
    
    int getMiddle(Node* head) {
       Node* first = head;
       Node* second = head;
       
       if(first == NULL) return -1;
       if(first -> next == NULL || second->next == NULL) return first->data;
       
       while(second!=NULL && second->next!=NULL){
           second = second -> next -> next;
           first = first -> next;
       }
       
       return first->data;
    }
};
// prove that the given linkedlist is palindromic 
// time complexity is o(n)
// space complexity is o(1)

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

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        Node* temp_1 = head;
        Node* temp_2 = head;
        
        if(head == NULL || head->next == NULL) return true;
        
        Node* prev = NULL;
        Node* res = NULL;
        while(temp_2!=NULL){
            res = temp_2->next;
            temp_2->next = prev;
            prev = temp_2;
            temp_2 = res;
        }
        
        // now use prev fror comparing
        while( temp_1 != NULL && prev !=NULL ){
            if(temp_1->data != prev->data){
                return false;
            }
            temp_1 = temp_1 -> next;
            prev = prev -> next;
        }
        return true;
    }
};
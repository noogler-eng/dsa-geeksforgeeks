// Find an intersection point of Y linkedist
// here Y is the shape point where all the three points are released
#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
class Node{
    public: 
        int data;
        Node* next = NULL;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


// it is simply appraoch as movign the same step forward to reach at same lenght
// the time complexity is o(n);
int hashMapWay(Node* &head1, Node* &head2){
    // length of linkedlist1 
    int length1 = 0, length2 = 0;
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    while(temp1!=NULL){
        length1++;
        temp1 = temp1->next;
    }

    while(temp2!=NULL){
        length2++;
        temp2 = temp2->next;
    }

    while(length2 > length1){
        head2 = head2->next;
        length2--;
    }

    while(length1 > length2){
        head1 = head1->next;
        length1--;
    }

    while(head2!=NULL && head1!=NULL){
        if(head2 == head1) return head2->data;
        head2 = head2->next;
        head1 = head1->next;
    }

    return -1;
}

int main(){
    // Creating the first linked list: 3 -> 1 -> 4
    Node* head1 = new Node(3);
    head1->next = new Node(1);
    head1->next->next = new Node(4);

    // Creating the second linked list: 1 -> 2
    Node* head2 = new Node(1);
    head2->next = new Node(2);

    // Creating the intersection part: 6 -> 2
    Node* intersectingNode = new Node(6);
    intersectingNode->next = new Node(2);

    // Linking the intersection part to the first list
    head1->next->next->next = intersectingNode;

    // Linking the intersection part to the second list
    head2->next->next = intersectingNode;

    // Find the intersection point using the hash map approach
    int common = hashMapWay(head1, head2);
    cout<<common<<endl;
    return 0;
}
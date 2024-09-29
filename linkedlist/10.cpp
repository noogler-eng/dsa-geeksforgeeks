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

// Node* reverseLinkedList(Node* head){
//     Node* temp = head;
//     Node* res = NULL;
//     Node* prev = NULL;

//     while(temp!=NULL){
//         res = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = res;
//     }

//     return prev;
// }

// int pointOfSection(Node* &head1, Node* &head2){
//     // we hvae to return the first common point
//     head1 = reverseLinkedList(head1);
//     head2 = reverseLinkedList(head2);

//     if(head1 != head2) return -1;

//     while(head1->next!= head2->next){
//         head1 = head1->next; 
//         head2 = head2->next;
//     }

//     return head1->data;
// }

// it is simply done by using hashmap
// the time complexity is o(n);
Node* hashMapWay(Node* &head1, Node* &head2){
    // time complexity is (1) on inserting and finding
    unordered_map<Node*, int> m;

    // traversing the first linkedlist
    // time complexity is (n1)
    while(head1!=NULL){
        m[head1] = 1;
        head1 = head1->next;
    }

    // traversing the second linkedlist
    // time coplexity is (n2)
    while(head2!=NULL){
        if(m.find(head2)!=m.end()){
            return head2;
        }
        head2 = head2->next;
    }

    return NULL;
}

void print(Node* common){
    Node* temp = common;
    
    while(temp!=NULL){
        cout<<common->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
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
    Node* common = hashMapWay(head1, head2);
    print(common);
    return 0;
}
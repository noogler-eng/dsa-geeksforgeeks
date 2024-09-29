// Design a browser history ( can be used in system design )
#include<iostream>
using namespace std;
class Node{
    public: 
        string data;
        Node* next;
        Node* prev;
        Node(string data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class Browser{
    
    public: 
    Node* start;
    Node* mostRecent;
    Node* mostPrev;
    Node* curr;
        Browser(string homePage){
            start = new Node(homePage);
            mostRecent = this->start;
            mostPrev = this->start;
            curr = this->start;
        }

        // on visiting new page at middle means delete all the forward hostory
        void visit(string newPage){
            Node* forwardNode = new Node(newPage);
            mostRecent->next = forwardNode;
            forwardNode->prev = mostRecent;
            mostRecent = forwardNode;
            curr = mostRecent;
        }


        string forward(int forwardSteps){
            while(forwardSteps > 0){
                if(curr -> next == NULL){
                    return curr->data;
                }
                curr = curr->next;
                forwardSteps--;
            }
            return curr->data;
        }
        
        string back(int backwardSteps){
            while(backwardSteps > 0){
                if(curr -> prev == NULL){
                    return curr->data;
                }
                curr = curr->prev;
                backwardSteps--;
            }
            return curr->data;
        }
};


int main(){
    Browser browser("www.google.com");
    browser.visit("www.google.com");
    browser.visit("www.insta.com");
    browser.visit("www.facebook.com");
    cout<<browser.back(1)<<endl;
    cout<<browser.back(1)<<endl;
    cout<<browser.forward(1)<<endl;
    browser.visit("www.github.com");
    cout<<browser.forward(1)<<endl;
    cout<<browser.back(1)<<endl;
    cout<<browser.back(1)<<endl;
    return 0;
}
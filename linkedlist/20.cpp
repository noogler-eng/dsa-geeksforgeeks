// find the pairs with a given sum in LLD
#include<iostream>
#include<vector>
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

// this is working but we need more optimization in this code
vector<pair<int,int>> DLLDeleteKey(Node* head, int sum){
    Node* temp1 = head;
    Node* temp2 = head->next;
    vector<pair<int, int>> ans;

    while(temp1!=NULL){
        temp2 = temp1->next;
        while(temp2!=NULL){
            if(temp1->data + temp2->data == sum){
                ans.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return ans;
}

void print(vector<pair<int,int>> ans){
    for(auto i: ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
}

int main(){

    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->prev = head;
    int x = 10;

    vector<pair<int,int>> ans = DLLDeleteKey(head, x);
    print(ans);
    return 0;
}
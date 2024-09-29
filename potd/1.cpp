// alternative postivie and negative number
// array contains both positive and negative number, we have to create the alternative
// positive and negative in same relative order.
// input: arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
// output: arr[] = {9, -2, 4, -1, 5, -5, 0, -3, 2}

#include<iostream>
#include<vector>
using namespace std;


// brute force:- 
// positive array = [9, 4, 5, 0, 2]
// negative array = [-2, -1, -5, -3]
// joing both one by one, start with positive
// time complexity is o(n) + o(n);
// space complexity is o(2n/2);
void new_sort(vector<int> &arr){
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] >= 0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }

    int i = 0, j=0, k=0;
    while(i<pos.size() && j<neg.size()){
        arr[k]=pos[i];
        i++;
        k++;
        arr[k]=neg[j];
        j++;
        k++;
    }

    while(i<pos.size()){
        arr[k] = pos[i];
        i++;
        k++;
    }

    while(j<neg.size()){
        arr[k] = pos[j];
        j++;
        k++;
    }

}


void print(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    new_sort(arr);
    print(arr);
    return 0;
}

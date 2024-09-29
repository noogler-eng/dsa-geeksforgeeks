// important problem
// josephus problem

#include<iostream>
#include<vector>
using namespace std;
// killing each other by making an circle with a gap of n
// 1, 2, 3, 4, 5, 6, 7, 8, 9
// 1 will kill 7
// 8 will kill 5
// 6 will kill 3
// ..
// one of them will be left it will kill himself

int josephusAlgo(vector<int> &persons, int k, int killer){
    // killing started from 1 taking gap of 7
    int n = persons.size();
    if(n == 1) return persons[0]; 

    int killedIndex = ((killer + k - 1) % n);
    // 0 + index we want to kill 
    persons.erase(persons.begin() + killedIndex);
    return josephusAlgo(persons, k, killedIndex);
}

int main(){
    int n = 40, k = 7;
    vector<int> persons(n);

    for(int i=0; i<persons.size(); i++){
        persons[i] = i + 1;
    }
    int safePosition = josephusAlgo(persons, k, 0); 
    cout<<"safePosition: "<<safePosition<<endl;
    return 0;
}

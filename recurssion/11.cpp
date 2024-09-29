// print all unique subsets - means no repetition os subsets
// first method - this can be done by using set which only contains unique elements

// variations - 
// 1. print subset / print power set / print all subsequnces all are smae
// 2.  power set contains all the subset of a set

// set - contains unique and in ascending order like abc....
#include<iostream>
#include<set>
using namespace std;

// here dont munuplate the original string as due to multiple recurssion 
void printAllUniqueSubset(string s, set<string> &myAns, string res){
    if(s.length() == 0){
        myAns.insert(res);
        return;
    }

    string res_1 = res + s[0];
    string res_2 = res;
    // removing the first element of string
    s.erase(0, 1);
    printAllUniqueSubset(s, myAns, res_1);
    printAllUniqueSubset(s, myAns, res_2);
}

void print(set<string> &s){
    for(auto it: s){
        cout<<it<<endl;
    }
}

int main(){
    string s = "aab";
    set<string> myAns;
    printAllUniqueSubset(s, myAns, "");
    print(myAns);
    return 0;
}
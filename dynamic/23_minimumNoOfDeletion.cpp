// minimum no of deletion to make the string palindromic
// 
#include<iostream>
#include<vector>
using namespace std;

// string x = agbcba
// string y = abcbga
// we have to make them palindromic both
// longest palindromic seq length
// total length od string - longest palindromic length seq
// output = 1

string reverseGivenString(string x){
    int start = 0;
    int end = x.length()-1;
    while(start<=end){
        swap(x[start], x[end]);
        start++;
        end--;
    }
    return x;
}

int minimumNoOfDeletionForpalindrom(string x){
    string y = reverseGivenString(x);
    int len_x = x.length();
    int len_y = y.length();

    vector<vector<int>> table(len_x+1, vector<int>(len_y+1, 0));

    // longest string length
    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1; j++){
            if(x[i-1] == y[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    return len_x - table[len_x][len_y];
}

int main(){
    string x = "agbcba";
    int ans = minimumNoOfDeletionForpalindrom(x);
    cout<<ans<<endl;
    return 0;
}
// we have to find the longes palindromic subseq
#include<iostream>
#include<vector>
using namespace std;
// string x = "agbcba"
// here palindromic subseq are - a, g, b, bcb, c
// longest palindromic subseq length = 3

// string x = agbcba
// string y = abcbga
// comming longest subseq - bcb - 3 ans
string reverseGivenString(string x){
    int start = 0;
    int end = x.length()-1;
    
    while(start<end){
        swap(x[start], x[end]);
        start++;
        end--;
    }
    return x;
}

pair<int, string> longestPlaindromicSubseq(string x){
    string y = reverseGivenString(x);
    int len_x = x.length();
    int len_y = y.length();

    vector<vector<int>> table(len_x+1, vector<int>(len_y+1, 0));
    string longest = "";

    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1; j++){
            if(x[i-1] == y[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
                // it is wrong not works
                // longest+=x[i-1];
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    // only work for printing case
    int i = len_x, j = len_y;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            longest+= x[i-1];
            i--;
            j--;
        }else{
            if(table[i][j-1] > table[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }

    return {table[len_x][len_y], longest};
}

int main(){
    string x = "agbcba";
    pair<int, string> ans = longestPlaindromicSubseq(x);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}
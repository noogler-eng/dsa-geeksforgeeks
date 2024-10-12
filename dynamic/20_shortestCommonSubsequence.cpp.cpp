// shortest common supersequence
#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
int shortestCommonSubSeq(string x, string y, int len_x, int len_y){
    // making an supersquence
    // 1. finding the longest common subsequence
    // 2. len_x + len_y - longest common subssequence return

    vector<vector<int>> table(len_x+1, vector<int>(len_y+1, 0));
    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1; j++){
            if(x[i-1] == y[j-1]){
                table[i][j] = 1 + table[i-1][j-1];
            }else{
                table[i][j] = max(table[i][j-1], table[i-1][j]);
            }
        }
    }

    return (len_x + len_y - table[len_x][len_y]);
} 

int main(){
    string x = "geek";
    string y = "eke";
    // merging them 
    // geekeke - longest
    // geeke - shortest
    // ans = geeke => 5

    // in subsequence order matters here
    // superseq -> seq1, seq2
    int ans = shortestCommonSubSeq(x, y, x.length(), y.length());
    cout<<ans<<endl;
    return 0;

}
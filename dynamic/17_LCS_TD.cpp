// longest common subsequence 
// dp using top down method
#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string x, string y, int len_x, int len_y){
    vector<vector<int>> table(len_x+1, vector<int>(len_y));
    for(int i=0; i<len_x+1; i++) table[i][0] = 0;
    for(int i=1; i<len_y+1; i++) table[0][i] = 0;

    // filling of the table
    // time complexity is o(n * n)
    // space comlexity is o(n * n)
    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1; j++){
            if(x[i-1] == y[j-1]){
                table[i][j] = 1 + table[i-1][j-1];
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    // printing the whole table
    for(int i=0; i<len_x+1; i++){
        for(int j=0; j<len_y+1; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    return table[len_x][len_y];
}


int main(){
    string x = "abcdgh";
    string y = "abedfhg";
    int ans = longestCommonSubsequence(x, y, x.length(), y.length());
    cout<<ans<<endl;
    return 0;
}
// longest common substring
// solved using tabluation method
#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
int LongestCommonSubstring(string x, string y, int len_x, int len_y){
    // initilization
    vector<vector<int>> table(len_x+1, vector<int>(len_y+1));
    for(int i=0; i<len_x+1; i++) table[i][0] = 0; 
    for(int j=0; j<len_y+1; j++) table[0][j] = 0;
    int longest = INT_MIN;

    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1; j++){
            if(x[i-1] == y[j-1]){
                table[i][j] = 1 + table[i-1][j-1];
                longest = max(longest, table[i][j]);
            }else{
                table[i][j] = 0;
            }
        }
    }

    return longest;
}

int main(){
    string x = "abcde";
    string y = "abfce";
    
    // common string part 
    // x = a b c d e
    // y = a b f c e
    // c = ab, c, e
    // longest common = 2;
    
    int ans = LongestCommonSubstring(x, y, x.length(), y.length());
    cout<<ans<<endl;
    return 0;
}
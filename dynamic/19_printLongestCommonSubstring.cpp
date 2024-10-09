// printing the longest common subsequence
// printing with the help of the dp top-down method
#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
string LongestCommonSubstring(string x, string y, int len_x, int len_y){
    // initilization
    vector<vector<string>> table(len_x+1, vector<string>(len_y+1, ""));
    string longest="";

    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1; j++){
            if(x[i-1] == y[j-1]){
                table[i][j] = table[i-1][j-1] + x[i-1];
                if(table[i][j].length() > longest.length()) longest = table[i][j];
            }else{
                table[i][j]="";
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
    
    string ans = LongestCommonSubstring(x, y, x.length(), y.length());
    cout<<ans<<endl;
    return 0;
}
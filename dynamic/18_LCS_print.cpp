#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
pair<int, string> getStringLCS(string x, string y, int len_x, int len_y){

    vector<vector<int>> table(len_x+1, vector<int>(len_y+1, 0));
    // getting the longest string here
    string longest = "";

    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1; j++){
            if(x[i-1] == y[j-1]){
                table[i][j] = 1 + table[i-1][j-1];
                longest += x[i-1];
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    return {table[len_x][len_y], longest};
}

int main(){
    string x = "acbcf";
    string y = "abcdaf";
    pair<int, string> p = getStringLCS(x, y, x.length(), y.length());
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}
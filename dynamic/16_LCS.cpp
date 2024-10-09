// LCS - longest common subsequence
// questions - 
// 1. longest common substring
// 2. print LCS
// 3. shortest common supersequence
// 4. print SCS
// 5. minimum no of insertion and deletion from a -> b
// 6. longest repeating subsequence
// 7. length of longest subsequence of which is a substring in b
// 8. subsequence pattern matching
// 9. count how many time a appears as a subsequence in b
// 10. longest palindromic subsequence
// 11. longest palindromic substring
// 12. count of palindromic substring
// 13. minimum no of deletion in a string to make it a palindorme
// 14. minimum no of insertion in a string to make it a palindrome


// 1. longest common subsequence
#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;

// memoization version
// dp comes when there is overlapping
int longestCommonSubsequence(string x, string y, int x_len, int y_len, vector<vector<int>> table){
    // table calls on variables which are changing while recursion
    if(x_len == 0 || y_len == 0) return 0;

    if(table[x_len][y_len] != -1) return table[x_len][y_len];
    if(x[x_len-1] == y[y_len-1]) return table[x_len][y_len] = longestCommonSubsequence(x, y, x_len-1, y_len-1, table) + 1;
    return table[x_len][y_len] = max(longestCommonSubsequence(x, y, x_len-1, y_len, table), longestCommonSubsequence(x, y, x_len, y_len-1, table));
}

// sending the length with them is easy....
int recusiveApproach(string x, string y, int x_len, int y_len){
    // base condition
    if(x_len == 0 || y_len == 0) return 0;

    // choice diagram
    if(x[x_len-1] == y[y_len-1]) return recusiveApproach(x, y, x_len-1, y_len-1) + 1;
    return max(recusiveApproach(x, y, x_len-1, y_len), recusiveApproach(x, y, x_len, y_len-1));
}

int main(){
    string x = "abcdgh";
    string y = "abedfhg";

    // x = a b c d g h
    // y = a b e d f h g
    // c = a b   d   h
    // common subsequnce = abdh -> 4
    // subsequnce is string which can be non continous but order is same

    // substring
    // here longest common substring is ab -> 2
    // substring is string which is continous and are in same order
    
    // recursive
    // 1. base condition
    // 2. choice diagram
    // 3. smalling the input 
    // recursive approach is starting from back - --

    // x length -> n 
    // y length -> m
    // base condition when anyone of them is 0

    int ans = recusiveApproach(x, y, x.length(), y.length());
    cout<<ans<<endl;

    vector<vector<int>> table(x.size()+1, vector<int>(y.size()+1, -1));
    int ans_ = longestCommonSubsequence(x, y, x.length(), y.length(), table);
    cout<<ans_<<endl;

    return 0;
}
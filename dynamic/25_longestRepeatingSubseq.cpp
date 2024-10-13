// longest repeating subsequence
#include<iostream>
#include<vector>
using namespace std;

// we have to find the longest repeating subseq
int longestRepeatingSubSeq(string x){
    string y = x;
    int len_x = x.length();
    int len_y = y.length();

    vector<vector<int>> table(len_x+1, vector<int>(len_y+1, 0));

    // as moving in same order 
    string longest = "";
    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1; j++){
            if(x[i-1] == y[j-1] && i != j){
                table[i][j] = 1 + table[i-1][j-1];
                // here the character will repeat
                // longest+=x[i-1];
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    int i = len_x, j = len_y;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1] && i!=j){
            longest+=x[i-1];
            i--;
            j--;
        }else{
            if(table[i-1][j] > table[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    
    // revrsing the string
    int start = 0;
    int end = longest.length()-1;
    while(start <= end){
        swap(longest[start], longest[end]);
        start++;
        end--;
    }

    cout<<longest<<endl;
    return table[len_x][len_y];
}

// repeating subseq 
// AABEBCDD
// ABD is same as order of ABD, simillar like others also

int main(){
    string x = "AABEBCDD";
    int ans = longestRepeatingSubSeq(x);
    cout<<ans<<endl;
    return 0;
}
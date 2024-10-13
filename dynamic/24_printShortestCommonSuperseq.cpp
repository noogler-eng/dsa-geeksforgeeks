// printing the shortest super common sequence
#include<iostream>
using namespace std;

// super common seq - string 1 anf string 2 combination
// length of supersequence is x + y - LCS

string reverseGivenString(string x){
    int start = 0;
    int end = x.length()-1;

    while(start <= end){
        swap(x[start], x[end]);
        start++;
        end--;
    }

    return x;
}

pair<int, string> shortestCommonSuperSeq(string x, string y){
    int len_x = x.length();
    int len_y = y.length();

    vector<vector<int>> table(len_x+1, vector<int>(len_y+1, 0));
    string longest = "";

    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1; j++){
            if(x[i-1] == y[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    int lenghtOfSuperSeq = len_x + len_y - table[len_x][len_y];

    // only work for printing case
    // acbcf and abcdaf
    // acbcdaf
    int i = len_x, j = len_y;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            longest+= x[i-1];
            i--;
            j--;
        }else{
            if(table[i][j-1] > table[i-1][j]){
                longest+= y[j-1];
                j--;
            }else{
                longest+= x[i-1];
                i--;
            }
        }
    }

    // here things are happeining from back so reversing it
    longest = reverseGivenString(longest);
    return {lenghtOfSuperSeq, longest};
}

int main(){
    string x = "acbcf";
    string y = "abcdaf";

    pair<int, string> ans = shortestCommonSuperSeq(x, y);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}
// sequence pattern matching
#include<iostream>
#include<vector>
using namespace std;
bool sequencePatternMatching(string x, string y){
    int len_x = x.length();
    int len_y = y.length();
    vector<vector<int>> table(len_x+1, vector<int>(len_y+1, 0));

    // range of LCS is from 0 to min(len_x, len_y)
    // according to this we will make the table
    // here length is sufficent for this problem
    string longest = "";
    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1; j++){
            if(x[i-1] == y[j-1]){
                table[i][j] = 1 + table[i-1][j-1];
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    int i = len_x, j = len_y;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
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
    if(y == longest) return true;
    return false;
}

int main(){
    string y = "xyz";
    string x = "adxcpy";
    bool ans = sequencePatternMatching(x, y);
    cout<<ans<<endl;
    return 0;
}
// minimum no of insertion and deletion to make one string same as another
#include<iostream>
#include<vector>
using namespace std;
int minInDe(string x, string y, int len_x, int len_y){
    vector<vector<int>> table(len_x+1, vector<int>(len_y+1, 0));

    for(int i=1; i<len_x+1; i++){
        for(int j=1; j<len_y+1;j++){
            if(x[i-1] == y[j-1]){
                table[i][j] = 1 + table[i-1][j-1];
            }else{
                 table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    int lengthOfCommon = table[len_x][len_y];
    return len_x + len_y - (2 * lengthOfCommon);
}
int main(){
    string x = "heap";
    string y = "pea";
    int ans = minInDe(x, y, x.length(), y.length());
    cout<<ans<<endl;
    return 0;
}
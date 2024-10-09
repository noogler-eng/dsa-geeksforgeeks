// unbounded kanpsack
// problems -
// 1. Rod cutting
// 2. coin-change - !
// 3. coin-change - !!
// 4. Maximum ribbion cut

// unbounded knapsack - in this there is no limit, limitless quantity
// items array -> there is limitless choices
// if the decision has been taken then here we can again came back to this
// multiple occourence of same item has been allowed, items is always in unproccessed state

// Rod Cutting
// we have to find the minimum price
#include<iostream>
#include<vector>
using namespace std;
int ribbionCutting(vector<int> length, vector<int> price, int N){
    // we have to construct a rog of length N
    vector<vector<int>> table(length.size()+1, vector<int>(N+1));
    // initlilazition of the table
    for(int i=0; i<length.size()+1; i++) table[i][0] = 0;
    for(int i=1; i<N+1; i++) table[0][i] = 0;

    // filling of the table
    for(int i=1; i<length.size()+1; i++){
        for(int j=1; j<N+1; j++){
            if(length[i-1] <= j){
                table[i][j] = max((table[i][j-length[i-1]] + price[i-1]), (table[i-1][j]));
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }

    // printing the table
    for(int i=0; i<length.size()+1; i++){
        for(int j=0; j<N+1; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    return table[length.size()][N];
}

int main(){
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = 8;  // length of rod
    int ans = ribbionCutting(length, price, N);
    cout<<ans<<endl;
    return 0;
}
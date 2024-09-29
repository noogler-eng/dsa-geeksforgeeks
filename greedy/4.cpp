// jump game - 1
// important question
#include<iostream>
#include<vector>
using namespace std;
// can we reach to the last by jumping
// on 0 we can't jump
bool isJump(vector<int> jump){

    // 2, 3, 1, 0, 4
    int i=0;
    int maxSteps = 0;
    while( i < jump.size()){
        if(i > maxSteps) return false;

        // no we are stepping to index
        maxSteps = max(maxSteps, jump[i] + i);
        i++;
    }
    return true;
}

int main(){
    vector<int> jump = {2, 3, 1, 0, 4};
    bool ans = isJump(jump);
    cout<<ans<<endl;
    return 0;
}

// optimized version
// class Solution {
//   public:
//     int canReach(int A[], int N) {
//         int maxIndex = 0;
        
//         int i=0;
//         while(i < N){
//             if(maxIndex >= N) return true;
//             if(i > maxIndex) return false;
            
//             maxIndex = max(maxIndex, A[i] + i);
//             i++;
//         }
//         return true;
        
//     }
// };
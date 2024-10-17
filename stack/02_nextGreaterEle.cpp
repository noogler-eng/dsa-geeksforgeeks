// next greater element (monotonic stack: any order but it must be specific)
// important question
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> arr){
    // brute force - o(n*n)
    // optimized - using stack
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    // time complety is o(2n)
    // space complexity is o(n)
    for(int i=arr.size()-1; i>=0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        
        if(!st.empty()){
            ans[i] = st.top();
            continue;
        }else{
            ans[i] = -1;
        }
        st.push(arr[i]);
    }

    return ans;
}

int main(){
    vector<int> arr = {6, 0, 8, 1, 3};
    vector<int>ans = nextGreaterElement(arr);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
// Missing And Repeating
// Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is 
// missing and one number 'B' occurs twice in array. Find numbers A and B.


//{ Driver Code Starts
#include <iostream>
#include<vector>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        long long int n = arr.size(), doublee;
        
        long long int sumL = 0, sumO = n * (n+1) / 2;
        
        for(int i=0; i<n-1; i++){
            sumL+=arr[i];
            if(arr[i] == arr[i+1]){
                doublee = arr[i];
            }
        }
        
        sumL+=arr[n-1];
        sumL-=doublee;
        
        // cout<<sumL<<endl;
        
        vector<int> ans;
        long long int missing = abs(sumO - sumL);
        ans.push_back(doublee);
        ans.push_back(missing);
        
        return ans;
    }
};
// kadane's algorithm
// given an integer array arr[], finding the contigious subarray(contains at lest one number)
// that has maximum sum and return its sum

// subarray -> any continous part of array is subarray

// input arr[] = [1, 2, 3, -2, 5];
// output 9 as sum of all

// input arr[] = [-1, -2, -3, -4];
// output -1

// brute force -> o(n*n) as making each and every subarray and finding max
// optmized -> kadane's algo o(n)


#include<iostream>
#include<vector>
using namespace std;

// brute force - o(n * n)
int getSum(vector<int> &arr){
    int n = arr.size()-1;

    int sum = 0, maxi = INT_MIN;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
        }
        maxi = max(maxi, sum);
    }
    return maxi;
}

// kadane's algo
int getSumByKadane(vector<int> &arr){
    int maxi = INT_MIN, sum = 0;

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        maxi = max(sum, maxi);
        if (sum < 0) {
            // why i want to include negative numbers so it become 0's
            // Reset sum if it becomes negative
            sum = 0; 
        }
    }
}

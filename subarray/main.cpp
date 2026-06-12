#include <iostream>
#include <vector>
using namespace std;


int n = 5;    
int arr[5] = {1, 2, 3, 4, 5};


// brute force optimized
void findSubarraySumBruteForce () {
    

    int maxSum = INT_MIN;
    for (int st=0; st<n; st++){
        int currSum = 0;
        for (int end=st; end<n; end++){
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }
    cout << "max subarray sum = " << maxSum << endl;
}

// kadane's algorithm 
void findSubArraySumKadaneAlgo () {
    int currSum = 0, maxSum = INT_MIN;
    for(int i=0; i<=n; i++){
        currSum+= arr[i];
        maxSum = max(currSum, maxSum);

        if(currSum < 0) {
            currSum = 0;
        }
    }

    cout << "max subarray sum = " << maxSum << endl;

}
int main() {
    findSubarraySumBruteForce();
    findSubArraySumKadaneAlgo();
}
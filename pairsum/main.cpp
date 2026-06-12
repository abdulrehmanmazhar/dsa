#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSumBruteForce(vector<int> nums, int target)
{
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }

    return ans;
}

vector<int> pairSumOptimized(vector<int> nums, int target)
{
    vector<int> ans;
    int n = nums.size();

    int i = 0, j = n-1;

    while(i<j){
        int pairSum = nums[i] + nums[j];
        if(pairSum>target){
            j--;
        }else if(pairSum<target){
            i++;
        }else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}


int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    bool isSorted = true;

    vector<int> ans;

    if(isSorted){
        ans =   pairSumBruteForce(nums, target);
    }else{
        // only optimized approach will work here as the array is sorted ascending order
         ans = pairSumOptimized(nums, target);
    }


    if (ans.size() >= 2)
    {
        cout << ans[0] << "," << ans[1] << endl;
    }
    else
    {
        cout << "No pair found" << endl;
    }
}
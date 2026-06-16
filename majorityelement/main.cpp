#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int majorityElementBruteForce(vector<int> nums)
{
    int n = nums.size();

    for (int val : nums)
    {
        int freq = 0;

        for (int el : nums)
        {
            if (el == val)
            {
                freq++;
            }
        }

        if (freq > n / 2)
        {
            return val;
        }
    }

    return -1;
}

int majorityElementOptimized(vector<int> nums)
{
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int freq = 1, ans = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }
        else
        {
            ans = nums[i];
            freq = 1;
        }

        if (freq > n / 2)
        {
            return ans;
        }
    }
    return -1;
}

int majorityElementMooreAlgo(vector<int> nums)
{
    int n = nums.size();


    int freq = 0, ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (freq==0)
        {
            ans = nums[i];
            freq = 1;
        }
        else if (nums[i] == ans)
        {
            freq++;
        }
        else
        {
            freq--;
        }

        if (freq > n / 2)
        {
            return ans;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15, 15, 15, 15};

    int majorityElement = majorityElementMooreAlgo(nums);

    cout << "majority element = " << majorityElement << endl;
}
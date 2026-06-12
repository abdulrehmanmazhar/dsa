#include <iostream>
#include <vector>
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

int main()
{
    vector<int> nums = {2, 7, 11, 15, 15, 15, 15};
    
    int majorityElement = majorityElementBruteForce(nums);

    cout << "majority element = " << majorityElement << endl;
}
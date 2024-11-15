#include <bits/stdc++.h>
using namespace std;

//! 2Sum

vector<int> twoSum(int n, vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

//! Sort Colors

void sortArray(vector<int> &arr, int n)
{

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

//! Majority Element

int majorityElement(vector<int> &nums)
{
    int n = nums.size(), key = nums[0], c = 0;
    for (int i = 0; i < n; i++)
    {
        if (c == 0)
            key = nums[i];
        if (nums[i] == key)
            c++;
        else
            c--;
    }
    return key;
}

//! Kadanes
int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxi = INT_MIN;
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        sum += nums[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
        i++;
    }
    return maxi;
}

int pairWithMaxSum(vector<int> &arr)
{
    // Your code goes here
    int N = arr.size();
    int ans = 0;

    // Iterate over the array
    for (int i = 1; i < N; i++)
        // Update ans with maximum sum of current and previous element
        ans = max(arr[i] + arr[i - 1], ans);

    // Return the maximum sum
    return ans;
}
int main()
{
}
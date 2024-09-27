#include <bits/stdc++.h>
using namespace std;

//! Binary Search

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int med = (low + high) / 2;
        if (nums[med] == target)
            return med;
        else if (nums[med] < target)
        {
            low = med + 1;
        }
        else
        {
            high = med - 1;
        }
    }
    return -1;
}

//! find floor

int findFloor(vector<long long> &v, long long n, long long x)
{

    // Your code here
    int start = 0, end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int med = (start + end) / 2;
        if (v[med] == x)
            return med;
        else if (v[med] < x)
        {
            start = med + 1;
            ans = med;
        }
        else
        {
            end = med - 1;
        }
    }
    return ans;
}

//! Search Insert

int searchInsert(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

//! Floor and ceil

int findFloor(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] <= x)
        {
            ans = arr[mid];
            // look for smaller index on the left
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // look on the right
        }
    }
    return ans;
}

int findCeil(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x)
        {
            ans = arr[mid];
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{
}
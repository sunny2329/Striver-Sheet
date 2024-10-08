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

//! Search Range

vector<int> searchRange(vector<int> &nums, int target)
{
    int sp = -1, ep = -1;
    vector<int> ans(2, 0);
    int s = 0, e = nums.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == target)
        {
            sp = mid;
            e = mid - 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    s = 0, e = nums.size() - 1;
    mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ep = mid;
            s = mid + 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    ans[0] = sp;
    ans[1] = ep;
    return ans;
}

//! Search In Rotated Array

int rotateSearch(vector<int> &nums, int target)
{
    int n = nums.size();
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[s] <= nums[mid])
        {
            if (target >= nums[s] && target < nums[mid])
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        else
        {
            if (target > nums[mid] && target <= nums[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

//! search in rotated array 2

bool rotatessearch(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
            return true;
        if ((nums[s] == nums[mid]) && (nums[e] == nums[mid]))
        {
            s++;
            e--;
        }
        else if (nums[s] <= nums[mid])
        {
            if (nums[s] <= target && nums[mid] > target)
                e = mid - 1;
            else
                s = mid + 1;
        }
        else
        {
            if (nums[mid] < target && nums[e] >= target)
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return false;
}

//! Find Minimum in Rotated Sorted Array

int findMin(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] < nums[e])
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    return nums[s];
}

//! Find the number of rotations

int findKRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

//! Single element in an array
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int s = 1, e = n - 2;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }

        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int s = 1, e = n - 2;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }

        if (nums[mid] > nums[mid - 1])
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int main()
{
}
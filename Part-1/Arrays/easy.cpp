#include <bits/stdc++.h>
using namespace std;

//! Largest Element in an Array

int largestElementInArray(vector<int> &arr)
{
    int ans = INT_MIN;
    for(int i = 0;i<arr.size();i++){
        ans = max(ans, arr[i]);
    }
    return ans;
}

//! Space Complexity --> O(1)
//! Time Complexity --> O(n) 
//! ------------------------------------------------------


//! Second largest element in an Array

int secondLargestElement(vector<int> &arr) {
    int largest = largestElementInArray(arr);
    int ans = INT_MIN;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] == largest) continue;
        ans = max(arr[i],ans);
    }
    if(ans == INT_MIN) return -1;
    return ans;
}

//! Space Complexity --> O(1)
//! Time Complexity --> O(n)
//! ----------------------------------------------------

//! Check if Array is sorted and rotated

bool check(vector<int> &nums){
    int count = 0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i] > nums[i+1]) count++;
    }
    if(nums[nums.size() - 1] > nums[0]) count++;
    return count <=1;
}





int main()
{
    vector<int> arr = {-199,222,341,5,45};
    cout << "Largest Element in the Array: " << secondLargestElement(arr) << endl;
    return 0;
}
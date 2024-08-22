#include <bits/stdc++.h>
using namespace std;

//! generate all binary strings without consecutive 1's

void helper(string &s, char prev, int counter, int n, vector<string> &ans) {
    if(counter == n) {
        ans.push_back(s);
        return;
    }
    
    // Append '0' and recurse
    s += '0';
    helper(s, '0', counter + 1, n, ans);
    s.pop_back();
    
    // Append '1' only if the previous character is not '1'
    if(prev != '1') {
        s += '1';
        helper(s, '1', counter + 1, n, ans);
        s.pop_back();
    }
}

//! generate parenthesis


void solve(string op, int open , int close, vector<string> &ans){
    if(open == 0 && close == 0){
        ans.push_back(op);
        return;
    } 
    if(open == close){
        op.push_back('(');
        
    }
}

vector<string> generateParenthesis(int n){
    int open = n;
    int close = n;
    vector<string> ans;
    string op = "";
    solve(op,open,close,ans);
    return ans;
}

vector<string> generateBinaryStrings(int n) {
    vector<string> ans;
    string s = "";
    helper(s, '0', 0, n, ans);  // Start with an empty string and counter = 0
    return ans;
}


//! subsets 

void helper1(int counter, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
    if(counter == nums.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[counter]);
    helper1(counter+1,temp,nums,ans);
    temp.pop_back();
    helper1(counter+1,temp,nums,ans);
}

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> temp;
    helper1(0,nums,temp,ans);
    return ans;
}




int main()
{
    int n = 3;
    vector<string> result = generateBinaryStrings(n);
    for(auto &s : result)
        cout << s << " ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


//! Print 1 to N without loop 
void printNos(int n){
    if(n == 0) return;
    printNos(n-1);
    cout << n << " ";
}

//! Print name N times without loop 
void printName(int n){
    if(n == 0) return;
    cout << "Sobhit" << " " ;
    printName(n-1);
}


//! Print N to 1 without loop   
void printNostwo(int n){
    if(n == 0) return;
    cout << n << " ";
    printNostwo(n-1);
}

//! Sum of first N natural number using recursion
int sum(int n){
    if(n == 0) return 0;
    return n + sum(n-1);
}

//! Factorial of a number using recursion
int fact(int n){
    if(n <= 1) return 1;
    return n * fact(n-1);
}

//! Reverse an array using recursion
void reverseArr(int arr[],int start,int end){
    if(start>=end) return;
    swap(arr[start++],arr[end--]);
    reverseArr(arr,start,end);
}

//! Check if a string is a palindrome or not using recursion
bool isPalindrome(string &s, int i){
    if(i>=s.length()/2) return true;
    if(s[i] != s[s.length() - i - 1]) return false;
    return isPalindrome(s, i+1);
}


//! Fibonacci number using recursion
int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}


int main()
{
}
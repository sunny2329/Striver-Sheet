#include <bits/stdc++.h>
#include <iostream> // for input and output operators
#include <math.h>   //for math functions

using namespace std;

// Function to compare n and m (an exercise for if-else)

string compareNM(int n, int m)
{
    // code here
    if (n < m)
        return "lesser";
    else if (n > m)
        return "greater";
    return "equal";
}



//Practice for switch case
double switchCase(int choice, vector<double> &arr)
{
    // code here
    double value = 0.0;
    switch (choice)
    {
    case 1:
        value = M_PI * arr[0] * arr[0];
        break;
    case 2:
        double L = arr[0];
        double B = arr[1];
        value = L * B;
        break;
    }
    return value;
}

int main()
{
    int x;
    cin >> x;
    cout << "First Work";
    cout << x;
}

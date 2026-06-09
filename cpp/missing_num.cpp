/*
You are given all numbers between 1,2,....,n except one. Your task is to find the missing number.
Input
The first input line contains an integer n.
The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
Output
Print the missing number.
Constraints

2<= n <= 2 x 10^5

Example
Input:
5
2 3 1 5

Output:
4
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n; // total number of integers;

    long long expected = (long long)n * (n + 1) / 2;  
    // long lon data type used incase the input is huge otherwise we can use int;
    long long actual = 0;

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x; // series of integers;
        // inclusive between 1 to n;
        if (x < 1 || x > n) {
            cout << "Invalid number: " << x << endl;
            return 1;
        }
        actual += x;
    }

    cout << "Missing number: " << expected - actual << endl;
    return 0;
}

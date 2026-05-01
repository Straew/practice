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
#include <vector>
int main () {
    int f_n, s_n;
    std::cout << "Enter a positive integer: ";
    std::cin >> f_n;
    std::vector <int> v_n;
    int i = f_n - 1;
    while (i!= 0) {
        std::cout << "Enter numbers containing between 1 to the first integer: ";
        std::cin >> s_n;
        if (1 <= s_n < f_n){
            v_n.push_back(s_n);
        }
        else {
            std::cout << "make sure the second line of integers are inclusive between 1 and first integers!";
        }
        i--;
    }
    
    for (int k = 1; k <= f_n; k++) {
        bool found = false;
        
        // Search for k in the vector
        for (int l = 0; l < v_n.size(); l++) {
            if (k == v_n[l]) {
                found = true;
                break;  // Found it, no need to continue searching
            }
        }
        
        // If not found, this is our missing number
        if ( found == false) {
            std::cout << "Output: " << k << std::endl;
            break;  // Found the missing number
        }
    }
    
    return 0;
}

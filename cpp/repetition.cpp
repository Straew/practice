/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. 
This is a maximum-length substring containing only one type of character.
Input
The only input line contains a string of n characters.
Output
Print one integer: the length of the longest repetition.
Constraints

1 <= n <= 10^6

Example
Input:
ATTCGGGA

Output:
3
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "enter series of A T C G "<< endl;  
    getline(cin, s);

    if (s.empty()) { cout << 0; return 0; }
    
    for (int i = 0; i < s.size(); i++) {
    s[i] = toupper(s[i]);   // transform to uppercase
    }

    int count = 1;
    int max_len = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            count++;                        // same char → loop
            if (count > max_len) max_len = count;
        } else {
            count = 1;                      // different char → break and start fresh
        }
    }

    cout << "Max number of repeated char->" << max_len << endl;
    return 0;
}

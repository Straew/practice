/*
Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
$$ 3  10  5  16  8 4  2 1$$
Your task is to simulate the execution of the algorithm for a given value of n.
Input
The only input line contains an integer n.
Output
Print a line that contains all values of n during the algorithm.
Constraints

1<= n < = 10^6

Example
Input:
3

Output:
3 10 5 16 8 4 2 1
*/

#include <iostream>
#include <vector>

int main (){
    int n;
    int *p = &n;
    std::cout << "Enter a positive integer:";
    std::cin >> n;
    std::vector <int> output;
    output.push_back(*p);
    
    if (*p<1){
        std::cout << "invalid number lad";
    }

    while (*p!=1){
        if (*p % 2 == 0){
            *p = *p/2;
            output.push_back(*p);
        }
        else {
            *p = (*p*3) +1 ;
            output.push_back(*p);
        }
    }
    for (int last_value : output){
        std::cout << last_value << " ";

    }
    delete p; //prevent memory leaks
}   

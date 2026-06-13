#include <iostream>
#include <vector>
#include <unordered_map>
int main () {
    int target_number;
    int size;
    std::unordered_map <int,int> index;
    std::cout<< "How many numbers you want to compare?"<<"\n";
    std::cin >> size;
    std::vector <int> s_n;
    int num;
    std::cout<< "enter series of numbers:"<<"\n";

    for (int i = 0; i < size; i++){
        std::cin >> num;
        s_n.push_back(num);
    }
    
    std::cout << "enter target number:"<< "\n";
    std::cin >> target_number;

    for (int i = 0; i < size; i++){
        int req_num = target_number - s_n[i];
        if (index.count(req_num)){
        std::cout << "output->" << s_n[index[req_num]] << " and "<<s_n[i] << "\n";
            return 1;
        }
        index[s_n[i]]= i;
    }
    std::cout << "lookslike the sum cant be found"<< "\n" ;
    
}



/*
 *two sums in 0(1) complexity:
 used vector to store values, and stack it in s_n
 then used a loop to go through the stack 
 then checks if the we have found the ouput
 for eg : target = 9
 and inputs are 2 7 11 15
 then what the loop does is takes 9 then subtract it with the current number
 if it matches we have found it but if it doesnt 
 it goes to store at index (unordered_map)
 which again stack the number then follow the loop until the loop is finished
 if its found we get the output if not
 get out the loop and prints the last statement;
 */

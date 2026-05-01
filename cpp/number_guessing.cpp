#include <iostream>
#include <cstdlib> // for rand
#include <ctime> // for srand

int main () {
    int GuessedNumber;
    srand(time(0));
    GuessedNumber = 1+(rand()%100);
    int UserNumber ;
    int i =3;
    
    while (i!=0){
    
    std::cout << "Enter a number: ";
    std::cin >> UserNumber;
       
    if ( UserNumber ==  GuessedNumber){
        std::cout << "You won";
        break;
    }
    else 
        std::cout << "Try again lol"<< "\n";

    i--;
    }
    std::cout <<"The number was:"<<GuessedNumber;
}



/* 1+(rand()%100) is the randomizer to create random numbers between 1 and 100
    and srand is used so random number is never the same eg: if the number was 84
    next time we run the code its gonna be diff.
*/

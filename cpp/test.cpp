#include <iostream>

int *Ptr () {
    int *x = new int;
    *x = 5;
    return x;
}

int main () {
    int *p = Ptr();
    std::cout << *p << "\n";
    delete p;
}

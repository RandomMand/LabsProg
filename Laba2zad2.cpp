#include <iostream>

using namespace std;

void f();                  // Для вызова f();
void f(const char*);       // Для вызова f("abc");
void f(int);               // Для вызова f(2);
void f(char, int);         // Для вызова f('+', 3);

int main () {
    f();
    f("abc");
    f(2);
    f('+', 3);
}


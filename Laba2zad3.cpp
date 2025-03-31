#include <iostream>

using namespace std;

int f(double a = 1.0){
    return a;
}
int f(long double a = 5.0){
    return a;
}
int main() {
    float f1 = 1.0f;
    double d = 2.0;
    long double ld = 3.0l;
    f();// f d
    f(4); // f d
    f(f1); // f d
    f(d); // f d
    f(ld); // f ld
}

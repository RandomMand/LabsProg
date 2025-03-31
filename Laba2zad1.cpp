#include <iostream>

using namespace std;

class Cls {
    int i;
public:
    Cls() {
        i = 1;
    }
    Cls& operator=(const Cls&) = delete;
};
void f(Cls * p, Cls * q) {
    *p = *q;
}

int main () {

}

//при вызове *p = *q; в функции f, компилятор выдаст ошибку, так как присваивание объектов Cls запрещено.

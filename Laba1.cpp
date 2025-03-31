#include <iostream>

using namespace std;

struct S {
    int x;
    S(int n) {
        x = n;
        printf(" Cons ");
    }
    S(const S & a) {
        x = a.x;
        printf(" Copy "); }
    ~S() {
        printf("Des ");
    }
};
S f( S & y ) {
    y = S(3);
    return y;
}
int main () {
    S s(1);
    f (s);
    printf("%d ", s.x);
    return 0;
}


/*В main создается объект s(1), вызывая конструктор Cons.

Функция f(s) создает временный объект S(3), вызывая Cons.

Присваивание y = S(3) вызывает конструктор копирования Copy.

Временный объект S(3) уничтожается, вызывая Des.

Возвращенный объект из f не создается заново, так как y — это s.

Выводится s.x, равный 3.

В конце работы main уничтожается s, вызывая Des. */

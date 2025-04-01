#include <iostream>

using namespace std;

int x = 4;

class A {
    int x;
public:
    A(int n = 1) : x(n) {}
    int f(int a = 0, int b = 0) { return a + b + x; }
};

class B : public A {
public:
    int x;
    B(int n = 2) : A(n), x(n) {}

    int f(int a) { return a + x; }
};

class C : public B {
    int x;
public:
    C(int n = 3) : B(n), x(n) {}

    int f(int a, int b) { return a + b + x; }

    int g(A *p) {
        return p->f(); //  f() в A требует аргументы по умолчанию return p->A::f();

    }
};

int main() {
    A *p;
    B b;
    C c;
    A a = c; //  C неявно приводится к A, но x в C скрывает x из A.   A a = static_cast<A>(c);


    struct D {
        B b;
        D() : b(5) {}
    } d;

    p = &b;

    x = c.g(&c);
    x = c.f();   // в C нет f() без параметров  x = c.B::f(0);


    x = c.f(x); //  f(int) определен в B, но C его скрывает  x = c.B::f(x);


    x = c.f(x, 1); // C::f(int, int)

    x = p->f(); //  A::f() требует 2 параметра с дефолтными значениями  x = p->A::f();


    x = p->f(x); // Вызов метода B::f(int), так как p указывает на B

    x = p->f(x, 1); //  B не имеет f(int, int), но A имеет x = p->A::f(x, 1);


    return 1;
}

/*B -> A()
C -> A() -> B() -> C()
A(const A&) // Копирование C в A
D -> A() -> B(5)

~D() -> ~B() -> ~A()
~A()
~C() -> ~B() -> ~A()
~B() -> ~A()
*/

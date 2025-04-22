#include <iostream>

using namespace std;

class A{
public:
    static int x;
    void get_0() const;
};
void A::get_0() const{
    cout << "Get 0";
}
int A::x;
int main () {
    const A a;
    a.x = 1;
    a.get_0();
    return 0;
}
____________________________________
#include <iostream>

using namespace std;

class A{
    static const char a;
public:
    static void f();
};

void A::f(){
    cout << "F";
}

const char A::a = '+';
int main () {
    A ob;
    A::f();
    return 0;
}
_________________________________________
#include <iostream>

using namespace std;

class A{
public:
    static void g();
    static void h();
};

void A::g(){
    cout << "g";
}
void A::h(){
    cout << "h";
}

int main () {
    const A x;
    A::g();
    x.h();
    return 0;
}

#include <iostream>
#include <cstring> 

using namespace std;

struct B {
    virtual void hi () {
        cout << "Hi!" << endl;
    }
};

struct D: B {
    char txt [10] [4];
};

void puthi (B * pb, D * pd) {
    pd = dynamic_cast<D*>(pb);
    if (!pd) return;

    for (int i = 0; i < 10; ++i) {
        strcpy(pd->txt[i], "Hi!");
    }
}

int main() {
    B base;
    D derived;

    cout << "Попытка вызвать puthi с указателем на B:" << endl;
    puthi(&base, nullptr); 

    cout << "Попытка вызвать puthi с указателем на D:" << endl;
    puthi(&derived, nullptr); 

    cout << "После вызова puthi:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << derived.txt[i] << endl;
    }

    return 0;
}
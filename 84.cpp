#include <iostream>
#include <cstring> 

using namespace std;

template <class T>
T max(T& x, T& y) {
    return x > y ? x : y;
}


template <>
const char* max(const char*& x, const char*& y) {
    return strcmp(x, y) > 0 ? x : y;
}

int main() {
    double x = 1.5, y = 2.8, z;
    int i = 5, j = 12, k;
    char* s1 = (char*)"abft";
    char* s2 = (char*)"abxde", *s3;

    z = max(x, y);
    cout << "z = " << z << endl;

    k = max<int>(i, j);
    cout << "k = " << k << endl;

    z = max(x, (double&)i);
    cout << "z = " << z << endl;

    z = max(y, (double&)j);
    cout << "z = " << z << endl;

    s3 = max(s1, s2);
    cout << "s3 = " << s3 << endl;

    cout << "Выбор сделан!" << endl;
    return 0;
}

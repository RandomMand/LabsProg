#include <iostream>

using namespace std;

class K {
public:
    virtual int f (int x){
        cout << "K::f" << endl;
        return 0;
    }
    virtual void g () {
        f (1);
        cout << "K::g" << endl;
    }
    virtual void h () {
        g ();
        cout << "K::h" << endl;
    }
};

class P: public K {
public:
    virtual int f (double y) {
        cout << "P::f" << endl;
        return 2;
    }
    virtual void g () {
        f (1);
        cout << "P::g" << endl;
    }
    virtual void h () {
        g();
        cout << "P::h" << endl;
    }
};

int main(){
    K k;
    P p;
    K *t = &p;
    t->f(0.7);
    t->g();
    t->h();
}

______________________________________________________________________
#include <iostream>

using namespace std;

class K {
public:
    virtual int f (int x){
        cout << "K::f" << endl;
        return 0;
    }
    void g () {
        f (1);
        cout << "K::g" << endl;
    }
    virtual void h () {
        g ();
        cout << "K::h" << endl;
    }
};

class P: public K {
public:
    int f (double y) {
        cout << "P::f" << endl;
        return 2;
    }
    virtual void g () {
        f (1);
        cout << "P::g" << endl;
    }
    virtual void h () {
        g();
        cout << "P::h" << endl;
    }
};
    int main(){
    K k; P p; K *t = &p;
    t -> f (0.7);
    t -> g ();
    t -> h ();
}
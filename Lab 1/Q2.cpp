#include <iostream>
using namespace std;
int main () {
    int value1 = 0, value2 = 1;
    int *p1, *p2;

    p1 = &value1;
    p2 = &value2;
    cout << "p1=" << p1 << "  p2=" << p2 << endl;
    *p1 = 10;
    *p2 = *p1;
    cout << "p1=" << *p1 << "  p2=" << *p2 << endl;
    p1 = p2;
    cout << "p1=" << p1 << "  p2=" << p2 << endl;
    *p1 = 20;
    cout << "p1=" << *p1 << "  p2=" << *p2 << endl;
    return 0;
}

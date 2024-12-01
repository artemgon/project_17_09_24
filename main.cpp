#include "classes.h"

int main() {
    Person p1("Alice"), p2("Bob"), p3("Charlie");
    Flat flat1(2);
    flat1.addPFunc(p1, 0);
    flat1.addPFunc(p2, 1);
    MDU mdu(2);
    mdu.addFFunc(flat1, 0);
    Flat flat2(1);
    flat2.addPFunc(p3, 0);
    mdu.addFFunc(flat2, 1);
    mdu.printFunc();
    return 0;
}
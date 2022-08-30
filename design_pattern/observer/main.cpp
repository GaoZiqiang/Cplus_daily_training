#include "object.h"
#include "observer.h"

int main() {
    Subject* sub = new Subject();

    sub->attach(new Obs1());
    sub->attach(new Obs2());

    sub->notify();
}
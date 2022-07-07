#include "box.h"
#include <stdio.h>

void Box::setWidth(double wid) {
    width = wid;
}

void printWidth(Box& box) {

    printf("width = %f\n", box.width);
}
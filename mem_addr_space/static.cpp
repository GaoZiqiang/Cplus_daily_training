#include <stdio.h>
#include "static.h"

int A::a = 1;

int main()
{
    printf("A::a: %d\n", A::a);
}
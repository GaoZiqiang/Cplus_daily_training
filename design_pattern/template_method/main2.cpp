#include "template2_lib.h"
#include "template2_app.h"

int main() {
    Library* pLib = new Application();
    pLib->run();

    delete pLib;
}
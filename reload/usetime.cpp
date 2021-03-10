#include <iostream>
#include "time.h"

using namespace std;

int main(){
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding.sum(fixing);
    cout << "total time of coding and fixing is ";
    total.Show();
    cout << endl;

    return 0;
}
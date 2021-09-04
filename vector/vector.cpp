#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv){
    std::vector<int> vec;
    for(int i=0;i<100;i++)    vec.push_back(i);
    printf("10:%d\n",vec[10]);
    printf("size:%d\n",vec.size());
    printf("**********************************\n");
    std::vector<int>::iterator it = vec.begin()+10;
    vec.erase(it);
    printf("10:%d\n",vec[10]);
    printf("size:%d\n",vec.size());
    return 0;
}
#include <iostream>

using namespace std;

void changeArr(int * arr);

int main() {

//    // 数组使用列表初始化时的几个易错点
//    // 1 数组在定义时可以同时进行初始化
//    int cards[4] = {1,2,3,4};// 定义并初始化
//    // 但是不可以先定义，再初始化
//    int hands[4];// 先定义
//    //hands = {1,2,3,4};// 再初始化--not allowed
//    // 可以使用下标分别给数组中的元素赋值
//    hands[0] = 1;
//    hands[1] = 2;
//    hands[2] = 3;
//    hands[3] = 4;
//
//    // 2 不可以将一个数组赋值给另一个数组
//    // hands = cards;// not allowed -- invalid array assignment
//
//    // 如下面所示，将数组中所有元素全部初始化为0
//    long totals = {0};
//
//
//    // C++11新增的数组初始化方法
//    // 1 初始化数组时，可省略等号 =
//    double earnings[3] {0.1,0.2,0.3};
//    // 2 {}中为空，表示初始化为0
//    float balance[100] {};
//    // 3 列表初始化进制缩窄转换
//    //long plifs[] = {25,92,3.0};// not allowed -- float3.0转换为int是缩窄操作
//    //char slifs[4] {'h','i',1122011,'\0'};// not allowed -- long 1122011不可以转换为char，超出8位
//    char tlifs[4] {'h','i',77,'\0'};// alowed -- int 12可以转换为char类型的M

    int arr[3] = {1,2,3};
//    printf("arr[0]: %d\n",*arr);
//    printf("arr[0]: %d\n",arr[0]);
//    printf("arr: %0x\n",arr);// 数组名为数组首地址 arr是指针 int指针
//    printf("sizeof(arr[]): %d\n",sizeof(arr));
//    printf("*(arr + 1): %d\n",*(arr + 1));
//    printf("&arr[1] == (arr + 1): %d\n",&arr[1] == (arr + 1));
    //printf("sizeof(arr): %d\n",sizeof(arr));
    int arr_len = sizeof(arr) / sizeof(arr[0]);// 注意：这里sizeof(arr)是整个数组的长度
    //std::cout << "arr_len: " << arr_len << std::endl;
    changeArr(arr);
    for (int i = 0; i < arr_len; i++) {
        std::cout << "arr " << i << ":" << arr[i] << std::endl;
    }
}
void changeArr(int * arr) {
    cout << "typeid(arr).name(): " << typeid(arr).name() << endl;
    cout << "arr[0]" << arr[0] << endl;
    cout << "arr[1]" << arr[1] << endl;
    cout << "arr[2]" << arr[2] << endl;

    // 修改数组元素
    arr[0] += 1;
    arr[1] += 1;
    arr[2] += 1;

//    printf("sizeof(arr) in changeArr: %d\n",sizeof(arr));
//    printf("sizeof(arr[0]): %d\n",sizeof(arr[0]));
      // 注意：这里sizeof(arr)是arr指针的长度--因此，需要显式传递数组长度
//    int arr_len = sizeof(arr) / sizeof(arr[0]);
//    std::cout << "arr_len: " << arr_len << std::endl;
//    for (int i = 0; i < arr_len; i++) {
//        //arr[i] += 1;
//        printf("arr: %d\n",arr[i]);
//    }
}
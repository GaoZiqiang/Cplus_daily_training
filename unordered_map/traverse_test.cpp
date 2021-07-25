/* unordered_map测试程序 */
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
//    unordered_map<string,string> mymap= {
//            {"gaoziqiang","boy"},
//            {"gaohan","boy"},
//            {"zhaihui","girl"}
//    };
//    // 遍历/迭代
//    cout << "mymap contains:" << endl;
//    for (auto it = mymap.begin();it != mymap.end();++it) {
//        cout << it->first << ":" << it->second << endl;
//    };
    string base_string = "/api/sum?n1=0&n2=18";
    int string_len = 8;
    cout << "result: " << std::string(base_string,string_len) << endl;






}
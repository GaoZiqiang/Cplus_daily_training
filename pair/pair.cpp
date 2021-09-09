// make_pair example
#include <utility>      // std::pair
#include <iostream>     // std::cout
#include <string>
#include <vector>

using namespace std;

int main () {
    std::pair <int,int> foo;
    std::pair <int,int> bar;

    // 复合类型
    std::pair <int, std::pair<std::string,double>> info;

    info = std::make_pair(1,std::make_pair("gaoziqiang",0.02));

    foo = std::make_pair (10,20);
    bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

    std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
    std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    std::cout << "bar: " << info.first << ", " << info.second.first << ", " << info.second.second <<  '\n';

    // 一个数组代表一个节点
    vector<pair<string,double>> node_id_info;
    node_id_info = {make_pair("node_id",1), make_pair("node_load",0.36),make_pair("cpu",0.69), make_pair("mem",0.88),
                    make_pair("disk",0.56), make_pair("net",0.88)};
    cout << "node_id_info:\n" << node_id_info[0].first << ": " << node_id_info[0].second << "\n" <<
    node_id_info[1].first << ": " << node_id_info[1].second << endl;
    // 遍历输出
    for (int i = 0; i < node_id_info.size(); i++)
        cout << node_id_info[i].first << ": " << node_id_info[i].second << " ";

    cout << endl;
    // 输出结果
    vector<pair<int, pair<int, double>>> node_infos;
    node_infos = {
            make_pair(1,make_pair(1,0.69)),
            make_pair(2,make_pair(1,0.32)),
    };
    for (int i = 0; i < node_infos.size(); i++) {
        cout << "node id: " << node_infos[i].first << " " << "job num: " << node_infos[i].second.first << " "
        << "node load: " << node_infos[i].second.second << endl;
    }



    return 0;
}
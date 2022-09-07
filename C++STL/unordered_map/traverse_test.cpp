/* unordered_map测试程序 */
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    //1 获取各节点连接数
    // 获取各节点当前运行作业数量--冯晨->监控模块
    // 调用监控模块的接口，依次遍历 获取各个节点当前运行作业数量，并加入node_job_map// 调用监控模块的接口，依插入草

    // 经过一系列插入操作初始化node_job_map

    // 得到node_job_map
    unordered_map<int,unordered_map<int,double>> node_job_load_map= {
            {node1, {{1,0.65}}},
            {node2, {{2,0.61}}},
            {node3, {{0,0.87}}},
            {node4, {{1,0.45}}},
            {node5, {{1,0.69}}},
            {node6, {{0,0.95}}},
            {node7, {{0,0.77}}},
            {node8, {{2,0.44}}},
            {node9, {{0,0.85}}},
            {node10, {{2,0.21}}},
            {node11, {{0,0.42}}},
            {node12, {{0,0.84}}},
            {node13, {{1,0.25}}},
            {node14, {{1,0.77}}},
            {node15, {{0,0.45}}},
            {node16, {{2,0.77}}},
            {node17, {{1,0.68}}},
            {node18, {{0,0.75}}},
            {node19, {{0,0.90}}}
            {node20, {{0,0.24}}}
    };

    // 排除作业数为2的节点 得到map_job_01
    // 创建临时map_job_01
    unordered_map<int,unordered_map<int,double>> map_job_01;
    // make_pair<int,<int,double>>
    for (auto it = node_job_load_map.begin();it != node_job_load_map.end();++it) {
        cout << it->first << ":" << it->second << endl;
        it->second;
        // {job,load}
        int node_id = it->first;
        auto sub_it = it->second.begin();
        int node_job_num = sub_it->first;
        double node_load = sub_it->second;
        if (node_job_num < 2) {
            map_job_01.insert({{node_id,{node_job_num,node_load}}});
        }
    };



    // 作业数为0的节点按照负载排序
    // 作业数为1的节点按照负载排序


    map or json {'node':job_num}
    //2 获取节点权重（total_score）
    // 对各节点根据权重进行排序 得到jobnum_weight_sorted_node_job_map

    //3 计算 得出目标节点










////    unordered_map<string,string> mymap= {
////            {"gaoziqiang","boy"},
////            {"gaohan","boy"},
////            {"zhaihui","girl"}
////    };
////    // 遍历/迭代
////    cout << "mymap contains:" << endl;
////    for (auto it = mymap.begin();it != mymap.end();++it) {
////        cout << it->first << ":" << it->second << endl;
////    };
//    string base_string = "/api/sum?n1=0&n2=18";
//    int string_len = 8;
//    cout << "result: " << std::string(base_string,string_len) << endl;






}
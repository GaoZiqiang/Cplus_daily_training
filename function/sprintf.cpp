#include <string>
#include <iostream>

using namespace std;

int main() {
    char buf[50];
    char name1[] = "gaoziqiang", name2[] = "gaohan";
    sprintf(buf,"name1 is %s, name2 is %s",name1,name2);
    printf("buf: %s\n",buf);

    char sql[200];
    int node_id = 8, job_num = 0;
    double total_load = 0.16, cpu = 0.21, mem = 0.21, disk = 0.09, net = 0.01;
    sprintf(sql,"insert into node_info (node_id,job_num,total_load,cpu,mem,disk,net) values(%s,%s,%s,%s,%s,%s,%s);",
            to_string(node_id).c_str(),to_string(job_num).c_str(),to_string(total_load).c_str(),to_string(cpu).c_str(),
            to_string(mem).c_str(),to_string(disk).c_str(),to_string(net).c_str());
    printf("sql: %s\n",sql);
}
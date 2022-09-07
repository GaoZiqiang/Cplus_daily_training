#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// unordered_map 怎么安装key和value进行排序

// 定义新的类型：重新定义vector，然后对vector按照规则排序
typedef pair<int, int> PAIR;
// 重载排序函数
int cmp_by_job(const PAIR& x, const PAIR& y)
{
    return x.first > y.first;   // 按照次数升序排序
}

int main()
{

    unordered_map<int,int> ans = {
            {1,1},
            {2,2},
            {3,3},
            {4,4}
    };

    vector<PAIR> vec;  // 重新定义类型
    // 将unordered_map 中的值重新装入新定义的vector中
    for(auto it=ans.begin();it!=ans.end();it++)
        vec.push_back(make_pair(it->first, it->second));
    sort(vec.begin(), vec.end(), cmp);  // vector根据cmp的规则进行排序
    for(int i=0;i<vec.size();i++)
        if(vec[i].second!=0) {

            cout << "vec[i].first: " << vec[i].first << endl;
            cout<< "vec[i].second: " << vec[i].second << endl;
        }
    cout<<endl;

    // system("pause");
}

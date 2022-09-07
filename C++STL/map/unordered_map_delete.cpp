// 试验STL中使用迭代器删除元素

#include <bits/stdc++.h>
#include <unordered_map>
#include <map>

using namespace std;
#define TOTAL 100
#define DEL_INT 3
/**
 * 删除map中所有值整除NUM的元素
 */
void fun(map<int,int> &map1, const int NUM )
{
    map<int, int>::iterator it;
    int i_Total = 0;
    for( it=map1.begin(); it!=map1.end(); )
    {
        if( it->second % NUM == 0 )
        {
            /**
             * 0 3 6 9 12 15 18 21 24 27 30 33 36 39 42 45 48 51 54 57 60 63 66 69 72 75 78 81 84 87 90 93 96 99
             */
            cout << it->second << " ";
            // 删除迭代器 注意：一定要用后置++ 既能保证删除目的元素 又能保证it继续向下遍历
            map1.erase(it++);
            ++i_Total;
        }
        else
        {
            it++;
        }
    }
    cout << endl << "i_Total=[" << i_Total << "]" << endl;
}

void deleteVec(vector<int>& nums, int n) {
    auto it = nums.begin();
    for (; it != nums.end();) {
        if (*it == n) {
            cout << "delete:" << *it << endl;
            nums.erase(it++);
        } else {
            it++;
        }
    }
    return;
}

int main( int argc, char **argv )
{
//    map<int, int> map1;
//
//    //初始化map1
//    for( int i=0; i<TOTAL; i++ )
//    {
//        map1.insert(pair<int, int>(i,i));
//        //map1[i] = i;
//    }
//
//    //删除整除3的元素
//    fun( map1, DEL_INT );
//
//    //查看最后的数据
//    map<int, int>::iterator it1;
//    for( it1=map1.begin(); it1!=map1.end(); ++it1 )
//    {
//        cout << "map1[" << it1->first << "]=[" << it1->second << "]" << endl;
//    }
    vector<int> nums = {1,2,3,4,5,5,6,5,6};
    deleteVec(nums, 5);

    return 0;
}
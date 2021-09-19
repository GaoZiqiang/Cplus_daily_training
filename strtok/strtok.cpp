#include <string>
#include <string.h>// strtok
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
//typedef vector<string> StringList;



vector<string> splitStr(const std::string str, char tag) {
    vector<string>  splited_str;
    std::string sub_str;

    //遍历字符串，同时将i位置的字符放入到子串中，当遇到tag（需要切割的字符时）完成一次切割
    //遍历结束之后即可得到切割后的字符串数组
    for(size_t i = 0; i < str.length(); i++)
    {
        if(tag == str[i]) //完成一次切割
        {
            if(!sub_str.empty())
            {
                splited_str.push_back(sub_str);
                sub_str.clear();
            }
        }
        else //将i位置的字符放入子串
        {
            sub_str.push_back(str[i]);
        }
    }

    if(!sub_str.empty()) //剩余的子串作为最后的子字符串
    {
        splited_str.push_back(sub_str);
    }

    return splited_str;
}

int main () {

    string key = "1&0.292634&0.999163&0.444752&0.197581&0.903255";
//    char key_char[10];
//    strcpy(key_char,key.c_str());
    char ss = '&';
    vector<string> res = splitStr(key,ss);
    printf("node id: %d\n",atoi(res[0].c_str()));
    for(int i = 0; i < res.size(); i++) {
        printf("res[%d]: %s\n",i, res[i].c_str());
    }

//    char *p;
//    p = strtok(key_char, ss);
//    printf("%s\n",p);
//    char str[80] = "POST /index.html?n1=1&n2=2 HTTP/1.1";
//    const char s[2] = "/";
//    char *token;
//
//    /* 获取第一个子字符串 */
//    token = strtok(str, s);
//    printf("%s\n",token);
//    char * token2 = strtok(NULL, s);
//    printf("%s\n",token2);
//
//    char * temp = strtok(token2,"?");
//    printf("%s\n",temp);
//    char * params1 = strtok(NULL,"");
//    printf("%s\n",params1);
//
//    char * params2 = strtok(params1," ");
//    printf("%s\n",params2);
//
//    char * param_n1 = strtok(params2,"&");
//    printf("%s\n",param_n1);
//    char * param_n2= strtok(NULL,"&");
//    printf("%s\n",param_n2);
//
//    char * n1 = strtok(param_n1,"=");
//    printf("%s\n",n1);
//    n1 = strtok(NULL,"=");
//    printf("%s\n",n1);// n1
//
//    char * n2 = strtok(param_n2,"=");
//    printf("%s\n",n2);
//    n2 = strtok(NULL,"=");
//    printf("%s\n",n2);// n2
//
//    printf("params: n1 = %s, n2 = %s\n",n1, n2);
//    printf("int params: n1 = %d, n2 = %d\n",atoi(n1), atoi(n2));

    /* 继续获取其他的子字符串 */
//    while( token != NULL ) {
//        printf( "%s\n", token );
//
//        token = strtok(NULL, s);
//    }

    return(0);
}
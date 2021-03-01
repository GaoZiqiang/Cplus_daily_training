// C++的结构struct

#include <iostream>
#include <cstring>

using namespace std;
//函數聲明
void printBook(struct Books *book);//注意：此處Books爲結構類型名
// 声明一个结构类型 Books
struct Books
{
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
};//没有声明结构变量

int main( )
{
    Books Book1;        // 定义结构体类型 Books 的变量 Book1
    Books Book2;        // 定义结构体类型 Books 的变量 Book2

    // Book1 详述
    strcpy( Book1.title, "C++ 教程");
    strcpy( Book1.author, "Runoob");
    strcpy( Book1.subject, "编程语言");
    Book1.book_id = 12345;

    // Book2 详述
    strcpy( Book2.title, "CSS 教程");
    strcpy( Book2.author, "Runoob");
    strcpy( Book2.subject, "前端技术");
    Book2.book_id = 12346;

    // 输出 Book1 信息
    cout << "第一本书标题 : " << Book1.title <<endl;
    cout << "第一本书作者 : " << Book1.author <<endl;
    cout << "第一本书类目 : " << Book1.subject <<endl;
    cout << "第一本书 ID : " << Book1.book_id <<endl;

    // 输出 Book2 信息
    cout << "第二本书标题 : " << Book2.title <<endl;
    cout << "第二本书作者 : " << Book2.author <<endl;
    cout << "第二本书类目 : " << Book2.subject <<endl;
    cout << "第二本书 ID : " << Book2.book_id <<endl;

    // 使用printBook函數打印信息
    cout << "第一本書信息： " << endl;
    printBook(&Book1);

    cout << "第二本書信息： " << endl;
    printBook(&Book2);

    return 0;
}

// 使用struct作为函数参数
void printBook(struct Books *book)
{
    cout << "书标题: " << book->title << endl;
    cout << "书作者: " << book->author << endl;
    cout << "书类目: " << book->subject << endl;
    cout << "书ID: " << book->book_id << endl;
}
// 实现方式：
// int* 整型指针变量

class Student {
public:
    Student()
    {
        m_pCount = new int;
        *m_pCount = 1;
    };

    ~Student()
    {
    };

    Student(const char *pszName);

    Student(Student &obj);

    Student &operator=(Student &obj);

    void release();

    void Show()
    {
        cout << hex << (int &) m_pszName << m_pszName << endl;
    }

private:
    char *m_pszName;
// 此处有个重点的混淆知识点
// 1、若使用public static int m_pCount，则在一个new资源块儿下可以实现计数功能
// 若出现多个new资源块儿时，将无法实现多个资源块儿的正确释放，因为static属于类共享而不是资源
// 块儿绑定。
// 2、若使用int m_pCount则与对象个数绑定，无法实现一个资源块儿下的多个对象m_pCount相同
// 则无法实现--m_pCount功能计数
// 3、为当前案例方式*m_pCount ，可以实现多个new资源块儿时，同步new m_pCount；
// 即可实现资源块儿与独立m_pCount资源的绑定，方便管理计数，此情况下，在拷贝的时候，将多个拷贝
// 关系的变量直接使用m_pCount地址传递，达到m_pCount资源在同一个资源块儿下多个对象共享的机制
    int* m_pCount; // 资源计数器，为0时可以被释放，避免重复释放问题

};
Student::Student(const char *pszName)
{
    m_pszName = new char[256];
    strcpy(m_pszName, pszName);
    m_pCount = new int;
    *m_pCount = 1;
}

Student::Student(Student &obj)
{
    m_pszName = obj.m_pszName;
    m_pCount = obj.m_pCount; // 指向同一个区域
    (*m_pCount)++;
}

Student& Student::operator=(Student &obj)
{
    if (m_pszName == obj.m_pszName) {
        return *this;
    }
    int count = --(*m_pCount);
    if(count == 0) {
        delete m_pszName;
        m_pszName = nullptr;
    }
    m_pszName = obj.m_pszName;
    m_pCount = obj.m_pCount;
    (*m_pCount)++;
    return *this;
}

void Student::release()
{
    if (m_pszName != NULL && --*m_pCount == 0) {
        delete m_pszName;
        m_pszName = NULL;
        delete m_pCount;
    }
}

int main()
{
    Student stu1("xiaoxiaosen2B");
    Student stu4("xiaoxiaosenSB");
    Student stu2;
    stu2 = stu1;
    Student stu3 = stu1;
    stu3.Show();
    stu2.Show();
    stu1.Show();
    stu1.release();
    stu2.release();
    stu3.release();
    cout << "hello world" << endl;
}
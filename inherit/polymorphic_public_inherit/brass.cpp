/*brass.cpp --bank accout class methods*/
#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

// formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f,precis p);

// Brass methods
Brass::Brass(const string &s,long an,double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt) {
    if (amt < 0)
        cout << "Negative deposit not allowed;" << "deposit is cancelled.\n";
    else
        balance += amt;
}

void Brass::Withdraw(double amt) {
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if(amt < 0)
        cout << "Withdrawal amount must be positive;" << "withdrawal cancelled.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "Withdrawal amount of $" << amt << " exceeds your balance.\n" << "Withdrawal cancelled.\n";

    restore(initialState,prec);
}

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct() const {
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;

    restore(initialState,prec);
}


// BrassPlus Methods
BrassPlus::BrassPlus(const string &s,long an,double bal,double ml,double r) : Brass(s,an,bal) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// 另一种构造函数
BrassPlus::BrassPlus(const Brass &ba,double ml,double r) : Brass(ba) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// 重载ViewAcct()方法
void BrassPlus::ViewAcct() const {
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();// 调用基类Brass的ViewAcct()方法输出基本信息
    // 下面是派生类BrassPlus新增的信息
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);// ###.### format
    cout << "Loan Rate: " << 100*rate << "%\n";
    restore(initialState,prec);
}

// 重载Withdraw()方法
void BrassPlus::Withdraw(double amt) {
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();// 取出bal的值
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;// 要借贷的金额
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);// 将银行借贷给的金额存入账户余额
        Brass:Withdraw(amt);// 然后取出amt金额
    }
    else
        cout << "Credit limit exceeded. Transaction cancelled.\n";

    restore(initialState,prec);
}

format setFormat() {
    // set up ###.## format
    return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}

void restore(format f,precis p) {
    cout.setf(f,std::ios_base::floatfield);
    cout.precision(p);
}
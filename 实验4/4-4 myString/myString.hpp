#include <iostream>
using namespace std;
class myString {
  public:
    //根据测试程序写构造函数原型
    myString(const char *s = NULL);
    myString(const myString &a, int start, int len);
    myString(int n, char s);
    myString(const myString &obj);
    void display() const;  //显示字符串
    void input();          //输入字符串
    int len() const;       //求字符串长
    //补充下标重载运算
    char &operator[](int index);

    //相等运算符重载
    friend int operator==(const myString &a, const myString &b);
    friend int operator==(const myString &a, const char *s);

    //>大于运算符重载
    friend int operator>(const myString &a, const myString &b);

    //+运算符重载
    friend myString operator+(const myString &a, const myString &b);
    friend myString operator+(const myString &a, const char *b);
    friend myString operator+(const char *a, const myString &b);

    //补充赋值重载运算
    myString operator=(const myString &obj);
    myString operator=(const char *s);
    //补充析构函数
    ~myString();

  private:
    char *str;
    int size;
};
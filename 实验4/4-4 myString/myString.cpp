#include "myString.hpp"
#include <iostream>
#include <string.h>
using namespace std;

//构造函数
myString::myString(const char *s) {
    if (s == NULL) {
        size = 0;
        str = new char[size + 1];
        strcpy(str, "");
    } else {
        size = strlen(s);
        str = new char[size + 1];
        strcpy(str, s);
    }
}

myString::myString(const myString &a, int start, int len) {
    str = new char[len + 1];
    memcpy(str, a.str + start, len);
    str[len + 1] = '\0';
}

myString::myString(int n, char s) {
    size = n;
    str = new char[n + 1];
    for (int i = 0; i < n; i++) {
        str[i] = s;
    }
    str[n + 1] = '\0';
}

//拷贝构造函数
myString::myString(const myString &obj) {
    size = obj.size;
    str = new char[size + 1];
    strcpy(str, obj.str);
}

//析构函数
myString::~myString() {
    if (str != NULL) {
        delete[] str;
        str = NULL;
        size = 0;
    }
}

//显示字符串
void myString::display() const {
    cout << str << endl;
}

//输入字符串
void myString::input() {
    char s[100];
    gets(s);
    size = strlen(s);
    strcpy(str, s);
}

//求字符串长
int myString::len() const {
    return size;
}

//补充下标重载运算
char &myString::operator[](int index) {
    return str[index];
}

//补充赋值重载运算
myString myString::operator=(const myString &obj) {
    if (str != NULL) {
        delete[] str;
        str = NULL;
        size = 0;
    }
    size = obj.size;
    str = new char[size + 1];
    strcpy(str, obj.str);
    return *this;
}

myString myString::operator=(const char *s) {
    if (str != NULL) {
        delete[] str;
        str = NULL;
        size = 0;
    }
    size = strlen(s);
    str = new char[size + 1];
    strcpy(str, s);
    return *this;
}

//相等运算符重载
int operator==(const myString &a, const myString &b) {
    if (a.size != b.size)
        return 0;
    for (int i = 0; i < a.size; i++) {
        if (a.str[i] != b.str[i])
            return 0;
    }
    return 1;
}
int operator==(const myString &a, const char *s) {
    if (a.size != strlen(s))
        return 0;
    for (int i = 0; i < a.size; i++) {
        if (a.str[i] != s[i])
            return 0;
    }
    return 1;
}

//>大于运算符重载
int operator>(const myString &a, const myString &b) {
    if (strcmp(a.str, b.str) > 0)
        return 1;
    return 0;
}

//+运算符重载
myString operator+(const myString &a, const myString &b) {
    myString c;
    c.size = a.size + b.size;
    c.str = new char[c.size + 1];
    strcpy(c.str, a.str);
    strcat(c.str, b.str);
    return c;
}

myString operator+(const myString &a, const char *b) {
    myString c;
    c.size = a.size + strlen(b);
    c.str = new char[c.size + 1];
    strcpy(c.str, a.str);
    strcat(c.str, b);
    return c;
}

myString operator+(const char *a, const myString &b) {
    myString c;
    c.size = strlen(a) + b.size;
    c.str = new char[c.size + 1];
    strcpy(c.str, a);
    strcat(c.str, b.str);
    return c;
}
#include "myString.hpp"
#include <iostream>
using namespace std;
int main() {
    char str[30] = "Sue likes hot weather.";
    myString a,            //空串
        b("I love ZJUT"),  //I love ZJUT
        c(str, 10, 11),    //hot weather
        d(3, 'a'),         //aaa
        e(b);              //I love ZJUT
    cout << "a:";
    a.display();
    cout << "b:";
    b.display();
    cout << "c:";
    c.display();
    cout << "d:";
    d.display();
    cout << "e:";
    e.display();

    if (b == str)
        cout << "equal";
    else
        cout << "not equal";
    cout << endl;

    if (b == e)
        cout << "equal";
    else
        cout << "not equal";
    cout << endl;

    a = c;
    a.display();

    if (d > e)
        d.display();
    else
        e.display();

    //输出字符串b的内容
    for (int i = 0; i < b.len(); i++)
        cout << b[i];
    cout << endl;

    b = "Steve is happy today.";
    cout << "b:";
    b.display();

    a.input();    //输入：Kate wasn't hungry.
    a.display();  //输出：Kate wasn't hungry.

    a = e + " and " + c;
    a.display();  //输出： I love ZJUT and hot weather
    getchar();
    getchar();
    return 0;
}
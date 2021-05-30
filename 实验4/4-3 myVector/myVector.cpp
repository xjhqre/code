#include "myVector.hpp"
#include <iostream>
using namespace std;

//用指定值value初始化n个单元  ,n<=CAPACITY
myVector::myVector(unsigned n, int value) {
    size = n;
    for (int i = 0; i < n; i++) {
        data[i] = value;
    }
}

//拷贝构造
myVector::myVector(const myVector &obj) {
    size = obj.size;
    for (int i = 0; i < obj.size; i++) {
        data[i] = obj.data[i];
    }
}

//冒泡排序
void myVector::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (data[j] > data[j + 1]) {
                int temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
    }
}

//赋值重载
myVector &myVector::operator=(const myVector &right) {
    this->size = right.size;
    for (int i = 0; i < right.size; i++) {
        this->data[i] = right.data[i];
    }
    return *this;
}

//下标运算
int &myVector::operator[](unsigned index) {
    if (index < 0 || index > size - 1) {
        cout << "下标越界！" << endl;
        exit(1);
    }
    return data[index];
}

//返回元素逆置存放的向量，即将原向量元素首尾交换的结果，注意原向量保持不变。
myVector myVector::operator-() {
    myVector res;
    for (int i = 0; i < size; i++) {
        res.data[i] = data[size - i - 1];
    }
    return res;
}

//调整容量
void myVector::set_size(unsigned newsize) {
    size = newsize;
}

//获取容量
int myVector::get_size() const {
    return size;
}

//从0开始显示向量元素
void myVector::display() const {
    for (int i = 0; i < size; i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
}

//表示求复杂可以求left和right的并集, 并集元素个数不超过CAPACITY
myVector operator+(const myVector &left, const myVector &right) {
    myVector res(left);
    int newsize = left.size;
    for (int i = 0; i < right.size; i++) {
        bool pd = 1;
        for (int j = 0; j < left.size; j++) {
            if (right.data[i] == left.data[j]) {
                pd = 0;
                break;
            }
        }
        if (pd == 1) {
            res.data[newsize] = right.data[i];
            newsize++;
        }
    }
    res.set_size(newsize);
    res.sort();
    return res;
}

//表示求left和right的差集
myVector operator-(const myVector &left, const myVector &right) {
    myVector res;
    int newsize = 0;
    for (int i = 0; i < left.size; i++) {
        bool pd = 1;
        for (int j = 0; j < right.size; j++) {
            if (left.data[i] == right.data[j]) {
                pd = 0;
                break;
            }
        }
        if (pd == 1) {
            res.data[newsize] = left.data[i];
            newsize++;
        }
    }
    res.set_size(newsize);
    res.sort();
    return res;
}
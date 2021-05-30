#include <iostream>
using namespace std;
const int CAPACITY = 1000;
class myVector {
  public:
    //����ϵ��
    myVector(unsigned n = 10, int value = 0);  //��ָ��ֵvalue��ʼ��n����Ԫ  ,n<=CAPACITY
    myVector(const myVector &obj);             //��������
    //��ֵ����
    myVector &operator=(const myVector &right);
    //�±�����
    int &operator[](unsigned index);
    //��������
    void set_size(unsigned newsize);  //����������newsize ,newsize<=CAPACITY
    //��ȡ����
    int get_size() const;

    //Ҳ����������������������
    //void expand(unsigned delta);//����������size+delta
    //void subtract(unsigned delta);//����������size-delta
    myVector operator-();  //����Ԫ�����ô�ŵ�����������ԭ����Ԫ����β�����Ľ����ע��ԭ�������ֲ��䡣

    void sort();  //��������

    void display() const;  //��0��ʼ��ʾ����Ԫ��

    friend myVector operator+(const myVector &left, const myVector &right);

    friend myVector operator-(const myVector &left, const myVector &right);

  private:
    int data[CAPACITY];
    int size;
};

//��ʾ���ӿ�����left��right�Ĳ���, ����Ԫ�ظ���������CAPACITY
myVector operator+(const myVector &left, const myVector &right);

//��ʾ��left��right�Ĳ
myVector operator-(const myVector &left, const myVector &right);

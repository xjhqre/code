#include <iostream>
using namespace std;
class myString {
  public:
    //���ݲ��Գ���д���캯��ԭ��
    myString(const char *s = NULL);
    myString(const myString &a, int start, int len);
    myString(int n, char s);
    myString(const myString &obj);
    void display() const;  //��ʾ�ַ���
    void input();          //�����ַ���
    int len() const;       //���ַ�����
    //�����±���������
    char &operator[](int index);

    //������������
    friend int operator==(const myString &a, const myString &b);
    friend int operator==(const myString &a, const char *s);

    //>�������������
    friend int operator>(const myString &a, const myString &b);

    //+���������
    friend myString operator+(const myString &a, const myString &b);
    friend myString operator+(const myString &a, const char *b);
    friend myString operator+(const char *a, const myString &b);

    //���丳ֵ��������
    myString operator=(const myString &obj);
    myString operator=(const char *s);
    //������������
    ~myString();

  private:
    char *str;
    int size;
};
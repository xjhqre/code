#include "position.hpp"
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	position a, b, c,d,e;
	a.set(5, 15);
	a.show();
	b.set(-4.5, 6.7);
	b.show();
	c.set(-10, -100);
	c.show();
	d.set(20.5, 5.5);
	e.set();//Ĭ��Ϊԭ��
	e.show();
	cout<<a.distance(b)<<endl;
	cout<<a.distance()<<endl;//Ĭ������ԭ��ľ���
	cout<<a.slope()<<endl;//��ԭ�㹹��ֱ�ߵ�б��
	cout<<a.slope(d)<<endl;	//��d����ֱ�ߵ�б��
	a.move(3);//��x��ƽ��
	a.show();
	b.move(-4, 5);
	b.show();
	c.move(0, 6);//��y��ƽ��
	c.show();
	return 0;
}


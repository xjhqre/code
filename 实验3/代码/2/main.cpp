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
	e.set();//默认为原点
	e.show();
	cout<<a.distance(b)<<endl;
	cout<<a.distance()<<endl;//默认求与原点的距离
	cout<<a.slope()<<endl;//与原点构成直线的斜率
	cout<<a.slope(d)<<endl;	//与d构成直线的斜率
	a.move(3);//沿x轴平移
	a.show();
	b.move(-4, 5);
	b.show();
	c.move(0, 6);//沿y轴平移
	c.show();
	return 0;
}


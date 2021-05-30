#include "Date.hpp"
#include <iostream>
using namespace std;

void Date::showDate()
{   cout<<year<<":"<<mon<<":"<<day<<":";
}

void Date::setDate()
{ do{  
      cin>>year>>mon>>day;
 }while(day<1||day>31||mon<1||mon>12);
}

long Date::normalize() { //确定天数 
	long sum = 0;
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	for (int i = 2000; i < year; i++){        //年份转天数，从2000年开始计数 
        if ((i % 4 == 4 && i % 100 != 0) || i % 400 == 0){
            sum += 366;
        }
        else{
            sum += 365;
        }
    }
    for (int i = 1; i < mon; i++){           //月份转天数 
        if (i == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)){
            sum += 29;
        }
        else{
            sum += days[i-1];
        }
    }
    sum += day;
    return sum;
}


//DateTime.cpp 
#include "Time.hpp"
#include <iostream>
using namespace std;

void DateTime::showTime()
{   cout<<year<<":"<<mon<<":"<<day<<":"<<hour<<":"<<minute<<":"<<second;
    cout<<endl;
}

void DateTime::setTime()
{ do{  
      cin>>year>>mon>>day>>hour>>minute>>second;
 }while(mon<1||mon>12||day<1||day>31||hour<0||hour>24||minute<0||minute>59||second<0||second>59);
}

double DateTime::diff(const DateTime& T)
{   long d=normalize()-T.normalize()-60;
    if(d<0) return 0;
    double h=d/60,m=d%60;
    if(m<15) return h;
    if(m>=15&&m<30) return h+0.5;
    if(m>=30&&m<60) return h+1;
}

long DateTime::normalize() const{  //天数转分钟 
    int d = countdays();
    return (hour + d * 24)*60+minute;
}

long DateTime::countdays() const{    //统计天数 
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

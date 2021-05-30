#include "Date.hpp"
#include "Time.hpp"
#include <iostream>
using namespace std;

void Time::showTime()
{   m_date->showDate();
    cout<<hour<<":"<<minute<<":"<<second;
    cout<<endl;
}

void Time::setTime()
{ do{  
      m_date = new Date;
      m_date->setDate();
      cin>>hour>>minute>>second;
 }while(hour<0||hour>24||minute<0||minute>59||second<0||second>59);
}

double Time::diff(Time& T)
{
    long d=normalize()-T.normalize()-60;
    if(d<0) return 0;
    double h=d/60,m=d%60;
    if(m<15) return h;
    if(m>=15&&m<30) return h+0.5;
    if(m>=30&&m<60) return h+1;
}

long Time::normalize() //天数转分钟
{
    return (hour + m_date->normalize() * 24)*60+minute;
}

#include "Date.hpp"
#include "Time.hpp"
#include <iostream>
using namespace std;

int main()
{
   Time arriveTime,leaveTime;
   double parkingTime;
   arriveTime.setTime();
   arriveTime.showTime();
   leaveTime.setTime();
   leaveTime.showTime();
   parkingTime = leaveTime.diff(arriveTime);
   cout << "parkingtime:" << parkingTime << "(h)" << endl;
   getchar();
   getchar();
   return 0;
}

#include "myVector.hpp"
#include <iostream>
using namespace std;

int main() {
    // int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b[10] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int a[10] = {45, 36, 78, 81, 12, 7, 66, 35, 27, 9}, b[10] = {23, 16, 76, 98, 43, 88, 26, 90, 41, 8};
    int loop;
    myVector aArray, bArray, cArray;
    for (loop = 0; loop < aArray.get_size(); ++loop) {
        aArray[loop] = a[loop];
        bArray[loop] = b[loop];
    }
    aArray.display();
    bArray.display();

    aArray.sort();
    aArray.display();

    cArray = -aArray;
    cArray.display();

    myVector dArray(aArray + bArray);
    dArray.display();

    cArray = aArray - bArray;
    cArray.display();
    getchar();
    getchar();
    return 0;
}

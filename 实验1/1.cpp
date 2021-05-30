#include<bits/stdc++.h>
using namespace std;

int * InitArray(unsigned n){
    int *a = new int[n];
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand();
    }
    return a;
}

void DisPlay(int *p, unsigned n){
    for (int i = 0; i < n; i++){
        cout << *(p+i) << " ";
    }
    cout << endl;
}

void SortArray(int *p, unsigned n){
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n - i; j++){
            if ((p[j]/100%10)*10+(p[j]%10) > (p[j+1]/100%10)*10+(p[j+1]%10)){
                int temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int main() {
    unsigned n;
    int *p;
    while (cin >> n){
        p = InitArray(n);
        cout << "排序前数组：";
        DisPlay(p, n);
        SortArray(p, n);
        cout << "排序后数组：";
        DisPlay(p, n);
        delete p;
    }
    return 0;
}
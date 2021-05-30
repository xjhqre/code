#include<bits/stdc++.h>
using namespace std;

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
    cin >> n;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        int *p = new int[k];
        for (int j = 0; j < k; j++){
            cin >> p[j];
        }
        SortArray(p, k);
        DisPlay(p, k);
        delete p;
    }
    return 0;
}
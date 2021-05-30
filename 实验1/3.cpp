#include <bits/stdc++.h>
using namespace std;

//��ʼ��������
void InitMatrix(int a[], int x, int y) {
    cout << "��������ֵ��" << endl;
    for (int i = 0; i < x * y; i++) {
        cin >> a[i];
    }
}

//������˺���
int **Multiply(int a[], int b[], int n, int k, int m) {
    int **c = new int *[2];  // ������̬��ά����c
    for (int i = 0; i < 2; i++) {
        c[i] = new int[4];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = 0;  //��ʼ��c�������ֵΪ0
            for (int v = 0; v < k; v++) {
                c[i][j] += a[i * k + v] * b[v * m + j];
            }
        }
    }
    return c;
}

//��ӡ�������
void disPlay(int **c, int n, int m) {
    cout << "�������c:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    const int n = 2;
    const int k = 3;
    const int m = 4;
    int a[n][k], b[k][m];
    int **c;
    InitMatrix(*a, n, k);
    InitMatrix(*b, k, m);
    c = Multiply(*a, *b, n, k, m);
    disPlay(c, n, m);
    for (int i = 0; i < 2; i++)
        delete[] c[i];
    delete[] c;
    return 0;
}
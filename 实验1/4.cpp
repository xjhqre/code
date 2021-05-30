#include<bits/stdc++.h>
using namespace std;

//��ʼ��������
void InitMatrix(int a[], int x, int y){
    cout << "��������ֵ��" << endl;
    for (int i = 0; i < x*y; i++){
        cin >> a[i];
    }
}

//������˺���
int **Multiply(int a[], int b[], int n, int k, int m){
    int **c = new int *[n]; // ������̬��ά����c
    for(int i=0;i<n;i++){
        c[i]=new int[m];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            c[i][j] = 0;
            for (int v = 0; v < k; v++){
                c[i][j] += a[i*k+v] * b[v*m+j];
            }
        }
    }
    return c;
}

//��ӡ�������
void disPlay(int **c, int n, int m){
    cout << "�������c:" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int n, k, m;
    cout << "������a����Ĺ�ģn,k��" << endl;
    cin >> n >> k;
    cout << "������b���������m��" << endl;
    cin >> m;
    int a[n][k], b[k][m];
    int **c;
    InitMatrix(*a, n, k);
    InitMatrix(*b, k, m); 
    c = Multiply(*a, *b, n, k, m);
    disPlay(c, n, m);
    getchar();
    getchar();
    return 0;
}
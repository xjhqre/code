## 矩阵乘法：
$$
a=
 \begin{bmatrix}
   1 & 2 & 3 \\
   4 & 5 & 6 \\
  \end{bmatrix} \\
 \ \\
  b= \begin{bmatrix}
   1 & 2 & 3 & 4\\
   5 & 6 & 7 & 8\\
   9 & 10 & 11 & 12\\
  \end{bmatrix} \\
  \ \\
  a \times b = c= \begin{bmatrix}
   34 & 44 & 50 & 56\\
   83 & 98 & 113 & 128\\
  \end{bmatrix} 
$$


## c++代码实现：
```cpp
#include<bits/stdc++.h>
using namespace std;

//初始化矩阵函数
void InitMatrix(int a[], int x, int y){
    cout << "输入矩阵的值：" << endl;
    for (int i = 0; i < x*y; i++){
        cin >> a[i];
    }
}

//矩阵相乘函数
int **Multiply(int a[], int b[], int n, int k, int m){
    int **c = new int *[n]; // 创建动态二维数组c
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

//打印输出函数
void disPlay(int **c, int n, int m){
    cout << "输出矩阵c:" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int n, k, m;
    cout << "请输入a矩阵的规模n,k：" << endl;
    cin >> n >> k;
    cout << "请输入b矩阵的列数m：" << endl;
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
```
## 运行结果截图：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210327002935722.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3hqaHFyZQ==,size_16,color_FFFFFF,t_70#pic_center)

#include<bits/stdc++.h>
using namespace std;

int upper = 0, lower = 0, dig = 0, space = 0, other = 0, number_word = 0;

int main() {
    string n;
    getline(cin, n);
    for (int i = 0; i < n.size(); i++){
        if ((n[i] - 'A' >= 0) && (n[i] - 'A' <= 25)){
            upper++;
        }
        else if ((n[i] - 'a' >= 0) && (n[i] - 'a' <= 25)){
            lower++;
        }
        else if ((n[i] - '0' >= 0) && (n[i] - '0' <= 9)){
            dig++;
        }
        else if (n[i] - ' ' == 0){
            space++;
        }
        else{
            other++;
        }
    }
    number_word = space+1;
    cout << "��д��ĸ��" << upper << endl;
    cout << "Сд��ĸ��" << lower << endl;
    cout << "�����ַ���" << dig << endl;
    cout << "�ո�" << space << endl;
    cout << "�����ַ���" << other << endl;
    cout << "��������" << number_word << endl;
    getchar();
    getchar();
    return 0;
}
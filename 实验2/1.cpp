#include<bits/stdc++.h>
using namespace std;

bool mystrncpy(char *to, char *from, unsigned startpos, unsigned len){
    if (startpos + len > strlen(from) || startpos < 0 || len <= 0 || startpos > strlen(from)-1){
        return false;
    }
    for (int i = 0; i < len; i++){
        to[i] = from[startpos+i];
    }
    return true;
}

int main() {
    char from[501] = {0};
    char to[501] = {0};
    int startpos, len;
    cout << "ÊäÈëfrom×Ö·û´®£º" << endl;
    cin >> from;
    cout << "ÊäÈë¿ªÊ¼Î»ÖÃºÍ¿½±´³¤¶È£º" << endl;
    cin >> startpos >> len;
    if (mystrncpy(to, from, startpos, len)){
        cout << "¿½±´³É¹¦£¬to×Ö·û´®Îª£º" << endl;
        for (int i = 0;  i < strlen(to); i++){
            cout << to[i];
        }
    }
    else cout << "¿½±´Ê§°Ü";
    getchar();
    getchar();
    return 0;
}
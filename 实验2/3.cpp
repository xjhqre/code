#include<bits/stdc++.h>
using namespace std;

string result; //存放结果

//比较两数大小并补零
void compare(string &s1, string &s2){
	while (s1.size() < s2.size()){
		s1 = '0' + s1;
	}
	while (s1.size() > s2.size()){
		s2 = '0' + s2;
	}
}

//加法
void add(string s1, string s2){
	compare(s1, s2);
	int len = s1.size();
	int carry = 0; //进位
	for (int i = len - 1; i >= 0; i--){
		int temp = (s1[i] - '0') + (s2[i] - '0') + carry;
		if (temp >= 10){
			carry = 1;
			result = to_string(temp % 10) + result;
		}
		else{
			carry = 0;
			result = to_string(temp) + result;
		}
	}
	if (carry == 1) result = '1' + result;
}

//减法
void sub(string s1, string s2){ 
	bool pd = true; //判断两数相减是否为正数
	compare(s1, s2);
	if (s2 > s1) pd = false;
	int carry = 0, len = s1.size();
	if (pd == false) swap(s1, s2);
	for (int i = len - 1; i >= 0; i--){
		int temp = (s1[i] - '0') - (s2[i] - '0') + carry;
		if (temp < 0){
			carry = -1;
			result = to_string(temp + 10) + result;
		}
		else {
			carry = 0;
			result = to_string(temp) + result;
		}
	}
	result = result.substr(result.find_last_of('0') + 1); //删除高位0
	if (pd == false) result = '-' + result;

}

//乘法
void multi(string s1, string s2){
	if (s1.size() < s2.size()) swap(s1, s2);
	int carry = 0;
	string s3[s2.size()];
	for (int i = s2.size() - 1; i >= 0; i--){
		for(int j = s1.size() - 1; j >= 0; j--){
			int temp = (s1[j] - '0') * (s2[i] - '0') + carry;
			if (temp >= 10){
				carry = temp / 10;
				s3[i] = to_string(temp % 10) + s3[i];
			}
			else{
				carry = 0;
				s3[i] = to_string(temp) + s3[i];
			}
		}
		if (carry != 0){
			s3[i] = to_string(carry) + s3[i];
			carry = 0;
		}
		for (int v = i; v < s2.size()-1; v++){
			s3[i] += '0';
		}
	}
	for (int i = 1; i < s2.size(); i++){
		while (s3[i].size() < s3[0].size()){
			s3[i] = '0' + s3[i];
		}
	}
	int carry2 = 0;
	for (int i = s3[0].size()-1; i >= 0; i--){
		int temp2 = 0;
		temp2 += carry2;
		for (int j = s2.size()-1; j >=0; j--){
			temp2 += s3[j][i] - '0';
		}
		if(temp2 >= 10){
			carry2 = temp2 / 10;
			result = to_string(temp2 % 10) + result;
		}
		else{
			carry2 = 0;
			result = to_string(temp2) + result;
		}
	}
}

int main() {
	string s1, s2, fh;
	while (cin >> s1){
		cin >> s2 >> fh;
		if (fh == "+") {
			add(s1, s2);
		}
		else if (fh == "-") {
			sub(s1, s2);
		}
		else if (fh == "*"){
			multi(s1, s2);
		}
		cout << result << endl;
		result.clear();
	}
	
	getchar();
	getchar();
	return 0;
}
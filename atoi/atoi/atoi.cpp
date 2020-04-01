#include <iostream>
#include <string>
using namespace std;

//思路：暴力解法，先把空格部分跳过，后判断是不是有效的字符串
int myAtoi(string str) {
	if (str.empty())
		return 0;
	int i = 0;
	while (str[i] == ' ')
		i++;
	int flag = 1;
	int s = 1;
	if (str[i] == '-'){
		flag *= -1;
		i++;
		s = 0;
	}
	if (s == 1){
		if (str[i] == '+')
			i++;
	}
	while (str[i] == '0')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return 0;
	int tmp = i;
	int count = 0;
	while (i < str.size() && (str[i] >= '0' && str[i] <= '9')){
		count++;
		i++;
	}
	if (count > 10){
		if (flag == 1)
			return flag * pow(2, 31) - 1;
		return flag * pow(2, 31);
	}
	i = tmp;
	count--;
	long sum = 0;
	while (i < str.size() && (str[i] >= '0' && str[i] <= '9')){
		int num = str[i] - '0';
		sum += num*pow(10, count--);
		i++;
	}
	if (sum > pow(2, 31) - 1){
		if (flag == 1)
			return flag * pow(2, 31) - 1;
		return flag * pow(2, 31);
	}
	return flag * sum;
}

int main()
{
	string s;
	cin >> s;
	int res = myAtoi(s);
	cout << res << endl;

	system("pause");
	return 0;
}
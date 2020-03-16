//整数反转，最重要的是注意边界
#include <iostream>
using namespace std;

//思路：先取模，将取到的模乘上相应的位数，最后判断边界

int reverse(int x) {
	int count = 0;
	long tmp = x;
	while (tmp / 10 != 0){
		count++;
		tmp /= 10;
	}
	tmp = x;
	long sum = 0;
	while (tmp / 10 != 0){
		sum += (tmp % 10) * pow(10, count--);
		tmp /= 10;
	}
	sum += tmp;
	if (sum > pow(2, 31) - 1 || sum < -1 * pow(2, 31))//int的范围
		return 0;
	return sum;
}

int main()
{
	int x = 0;
	cin >> x;
	int result = reverse(x);
	cout << result << endl;
	system("pause");
	return 0;
}
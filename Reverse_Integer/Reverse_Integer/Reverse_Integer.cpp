//������ת������Ҫ����ע��߽�
#include <iostream>
using namespace std;

//˼·����ȡģ����ȡ����ģ������Ӧ��λ��������жϱ߽�

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
	if (sum > pow(2, 31) - 1 || sum < -1 * pow(2, 31))//int�ķ�Χ
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
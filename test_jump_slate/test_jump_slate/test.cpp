////˼·��̰��+���ݣ�����ֻͨ��%50(�ֲ����ţ����������Ž⣬ֻ��һ����һ��Ľ�)
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int Isapproximate(int x, int y){
//	for (int i = y - 1; i > 1; i--){
//		if (x % i == 0)
//			return i;
//	}
//	return 0;
//}
//int main(){
//	int m = 0;
//	int n = 0;
//	while (cin >> m >> n){
//		if (m == n)//��m==nʱ������ֱ�ӷ���
//			cout << 0 << endl;
//		else{
//			vector<int> v;
//			int ans = Isapproximate(m, m);
//			int sum = m;
//			int y = m;
//			int count = 0;
//			while (ans){
//				v.push_back(ans);//��¼ÿ�����ľ���
//				sum += ans;
//				if (sum < n){//���û��ָ����λ�ã��Ƚ����Ĳ���++��������
//					y = sum;
//					count++;
//				}
//				else if (sum > n){//������Ĵ��ˣ������
//					sum -= v[v.size() - 1];
//					y = v[v.size() - 1];
//					v.pop_back();
//				}
//				else{//�����ȣ�����
//					count++;
//					cout << count << endl;
//					break;
//				}
//				ans = Isapproximate(sum, y);
//				while (ans == 0 && !v.empty()){//����
//					sum -= v[v.size() - 1];
//					ans = Isapproximate(sum, v[v.size() - 1]);
//					v.pop_back();
//				}
//				if (ans == 0 && v.empty())
//					cout << -1 << endl;
//			}
//		}
//	}
//	return 0;
//}

//˼·������̬�滮

//���ö�̬�滮˼����⡣����һ��vector����steps��steps[i]��ʾ����i��ʯ���������С������
//��ʼ��Ϊsteps����ΪINT_MAX�������N��ʯ�忪ʼ���������
//��steps[i]ΪINT_MAX����ʾ�õ㲻�ɵ��ֱ�ӿ�ʼ�´�ѭ����
//��steps[i]��ΪINT_MAX����ʾ�õ���Ե�����������i��Լ�������ж�̬�滮����̬�滮��ת�Ʒ���Ϊ
//steps[i + j] = min(steps[i] + 1, steps[i + j])   //iΪʯ���ţ�jΪi��Լ��
//steps[N] = 0


#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int N, M;
	while (cin >> N >> M){
		vector<int> steps(M + 1, INT_MAX);
		steps[N] = 0;
		for (int i = N; i <= M; i++){
			if (steps[i] == INT_MAX){
				continue;
			}
			for (int j = 2; (j*j) <= i; j++){
				if (i%j == 0){
					if (i + j <= M){
						steps[i + j] = min(steps[i] + 1, steps[i + j]);
					}
					if (i + (i / j) <= M){//�����ʹ���������Լ����ʹ�㷨����Ч��
						steps[i + (i / j)] = min(steps[i] + 1, steps[i + (i / j)]);
					}

				}

			}
		}
		if (steps[M] == INT_MAX){
			steps[M] = -1;
		}
		cout << steps[M] << endl;
	}

	system("pause");
	return 0;
}
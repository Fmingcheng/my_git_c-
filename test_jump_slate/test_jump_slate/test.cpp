////思路：贪心+回溯，用例只通过%50(局部最优，并不是最优解，只是一个优一点的解)
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
//		if (m == n)//当m==n时不用跳直接返回
//			cout << 0 << endl;
//		else{
//			vector<int> v;
//			int ans = Isapproximate(m, m);
//			int sum = m;
//			int y = m;
//			int count = 0;
//			while (ans){
//				v.push_back(ans);//记录每次跳的距离
//				sum += ans;
//				if (sum < n){//如果没到指定的位置，先将跳的步数++，继续跳
//					y = sum;
//					count++;
//				}
//				else if (sum > n){//如果跳的大了，则回溯
//					sum -= v[v.size() - 1];
//					y = v[v.size() - 1];
//					v.pop_back();
//				}
//				else{//如果相等，返回
//					count++;
//					cout << count << endl;
//					break;
//				}
//				ans = Isapproximate(sum, y);
//				while (ans == 0 && !v.empty()){//回溯
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

//思路二，动态规划

//采用动态规划思想求解。创建一个vector容器steps，steps[i]表示到达i号石板所需的最小步数。
//初始化为steps容器为INT_MAX。从序号N的石板开始逐个遍历，
//若steps[i]为INT_MAX，表示该点不可到达，直接开始下次循环。
//若steps[i]不为INT_MAX，表示该点可以到达，下面求解编号i的约数，进行动态规划。动态规划的转移方程为
//steps[i + j] = min(steps[i] + 1, steps[i + j])   //i为石板编号，j为i的约束
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
					if (i + (i / j) <= M){//这样就处理了两个约数，使算法更有效率
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
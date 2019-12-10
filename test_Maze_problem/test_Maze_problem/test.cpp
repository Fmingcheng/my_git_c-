//˼·�����ݣ�����ǽ�ͷ���
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string>& mazes(vector<string>& ret, vector<vector<char>> vv, int row, int col){
	int i = 0;
	int j = 0;
	//ģ�����Թ��Ķ���
	while (i != row - 1 || j != col - 1){
		while ((i < row && j < col)){
			if (vv[i][j] == '0'){
				string s;
				s += "(";
				s += i + '0';
				s += ",";
				s += j + '0';
				s += ")";
				ret.push_back(s);
				vv[i][j] = '2';//���߹���·�������
				j++;
				if (i == row - 1 && j == col - 1)
					break;
			}
			//�����������ͬ��������ͬ��ס����ԭ·����
			else if (vv[i][j] == '2'){
				//�������ȸ����������ߣ������£����������߶��Ǵ��������
				if (vv[i + 1][j] == '0'){//�ߵ���·�ڣ�����û��ͨ·
					i++;
					continue;
				}
				vv[i][j] = '1';
				if ((j > 0 && j < col) && vv[i][j - 1] == '2')
					j--;
				else
					i--;
				ret.erase(ret.begin() + ret.size() - 1);
			}
			else{
				if (j > 0)
					j--;
				else
					i--;
				if (vv[i + 1][j] == '0')
					i++;
				else
					vv[i + 1][j] = '1';
			}
		}
		//���Ѿ��ߵ����һ��
		while (i < row - 1){
			j--;
			i++;
			//�������ߣ�����
			if (vv[i][j] == '0')
				break;
			//�����У���������
			else{
				i--;
				vv[i][j] = '1';
				ret.erase(ret.begin() + ret.size() - 1);
			}
			if (vv[i][j - 1] == '1'){
				vv[i][j] = '1';
				i--;
				break;
			}
		}
	}

	string s;
	s += "(";
	s += i + '0';
	s += ",";
	s += j + '0';
	s += ")";
	ret.push_back(s);

	return ret;
}

int main(){
	int row = 0;
	int col = 0;
	while (cin >> row >> col){
		//��ʼ���Թ�
		vector<vector<char>> vv;
		vv.clear();
		vector<string> ret;
		ret.clear();
		vv.resize(row);
		for (int i = 0; i < vv.size(); i++)
			vv[i].resize(col);
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
				cin >> vv[i][j];
		}
		mazes(ret, vv, row, col);
		for (auto e : ret)
			cout << e << endl;
	}

	return 0;
}

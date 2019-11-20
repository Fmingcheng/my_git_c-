//z字形变换
//将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
//
//比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
//
//L   C   I   R
//E T O E S I I G
//E   D   H   N

//思路：通过将z字形变换后得数据放入一个二维数组，遍历二维数组


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (s.empty() || numRows == 1)
			return s;
		vector<vector<char>> vv;
		vv.resize(numRows);
		//算他要多少列
		int symbol = 0;
		int numCols = 0;
		int x = numRows - 2;
		if (numRows > s.length())
			numCols = 1;
		else{
			while (symbol < s.length()){
				if (symbol == s.length())
					break;
				numCols += 1;
				symbol += numRows;

				while (x-- && symbol < s.length()){
					numCols++;
					symbol++;
				}
			}
		}
		//这个注释掉的计算方法是错的，上面计算列的方法比较直白
		/*int tmp = 2*numRows-2;
		int numCols = (s.length()/tmp)*(numRows-1);
		if(s.length() % tmp != 0){
		if(s.length() % tmp > numRows)
		numCols += 2;
		else
		numCols++;
		}*/
		//初始化
		for (int i = 0; i < numRows; i++)
			vv[i].resize(numCols, ' ');
		int dig = 0;//记录s
		int count = numRows;
		int n = 0;
		while (dig < s.length() && n < numCols){//在数组中插入字符串
			if (count == numRows){
				for (int j = 0; j < numRows; j++){
					if (dig == s.length())
						break;
					vv[j][n] = s[dig++];
				}
			}
			else{
				for (int j = 0; j < numRows; j++){
					if (dig == s.length())
						break;
					if (j == (count - 1))
						vv[j][n] = s[dig++];
				}
			}
			count--;
			n++;
			if (count == 1)
				count = numRows;
		}
		//遍历数组，将得到的答案放入字符串当中
		string vs;
		for (int i = 0; i < vv.size(); i++){
			for (int j = 0; j < vv[0].size(); j++){
				if (vv[i][j] != ' ')
					vs += vv[i][j];
			}
		}
		return vs;
	}

	void Test(){
		string s("LCIRETOESIIGEDHN");
		string vs = convert(s, 3);
		cout << vs << endl;
	}
};

int main(){
	Solution s;
	s.Test();
	system("pause");
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//˼·��һ��һ���Ƚϣ���ǰ׺���ҳ�����Ȼ��ǰ׺�ͺ������Ƚ������µ�ǰ׺
string longestCommonPrefix(vector<string>& strs) {
	string s;
	if (strs.empty())
		return s;
	if (strs.size() == 1)
		return strs[0];
	for (int i = 0; i < strs[0].size(); i++){
		if (i < strs[1].size() && strs[0][i] == strs[1][i])
			s += strs[0][i];
		else
			break;
	}
	if (s.empty())
		return s;
	for (int i = 2; i < strs.size(); i++){
		string tmp;
		for (int j = 0; j < s.size(); j++){
			if (j < strs[i].size() && s[j] == strs[i][j])
				tmp += s[j];
		}
		s = tmp;
	}
	return s;
}


int main()
{
	vector<string> vt;
	vt.push_back("aca");
	vt.push_back("cba");
	string s;
	s = longestCommonPrefix(vt);
	cout << s << endl;
	system("pause");
	return 0;
}
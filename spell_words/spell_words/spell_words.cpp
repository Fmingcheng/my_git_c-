#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

//˼·����map��chars�е���ĸ���棬Ȼ�����words

int countCharacters(vector<string>& words, string chars) {
	map<char, int> m;
	for (int i = 0; i < chars.size(); i++){//��chars�е�������map��
		if (m.find(chars[i]) != m.end())//���������ͬ��Ԫ�������
			m[chars[i]]++;
		m.insert(pair<char, int>(chars[i], 1));//����������µ�Ԫ��
	}
	int count = 0;//��¼�����յ����е���֮��
	for (int i = 0; i < words.size(); i++){
		int flag = 0;
		map<char, int> tmp(m);
		for (int j = 0; j < words[i].size(); j++){
			if (tmp.find(words[i][j]) == tmp.end()){
				flag = 1;
				break;
			}
			else if (tmp[words[i][j]] == 0){
				flag = 1;
				break;
			}
			else
				tmp[words[i][j]]--;
		}
		if (flag != 1)
			count += words[i].size();
	}
	return count;
}


int main()
{
	vector<string> vt;
	vt.push_back("hello");
	vt.push_back("world");
	vt.push_back("leetcode");
	string s("welldonehoneyr");
	int result = countCharacters(vt, s);

	cout << result << endl;
	system("pause");
	return 0;
}
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

//思路：用map将chars中的字母储存，然后遍历words

int countCharacters(vector<string>& words, string chars) {
	map<char, int> m;
	for (int i = 0; i < chars.size(); i++){//将chars中的数存入map中
		if (m.find(chars[i]) != m.end())//如果存在相同的元素则记数
			m[chars[i]]++;
		m.insert(pair<char, int>(chars[i], 1));//否则，则插入新的元素
	}
	int count = 0;//记录所掌握的所有单词之和
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
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string stringIn;
	vector<string> words;
	int ii = 0, kk, jj, word_num;

	getline(cin, stringIn);

	do {
		kk = stringIn.find(' ', ii);
		if ((-1) != kk) {
			if (4 == (kk - ii)) {
				string tempword;

				tempword = stringIn.substr(ii, 4);
				words.push_back(tempword);
			}
			else if (1 == (kk - ii)) {		//�����Ŀո�����һ���ո�����
			}
			else {
				return -1;					//�����ַ���������
			}

			ii = kk + 1;
		}
		else {
			string tempword;
			if (4 == (stringIn.size() - ii))
				tempword = stringIn.substr(ii, 4);
			else
				return -1;

			words.push_back(tempword);
		}
	} while ((-1) != kk);

	word_num = (int)words.size();
	if (word_num< 2) return -1;		//�ַ�������С��2���˳�

	string head, end;
	for (ii = 0; ii < word_num; ii++) {
		head += words[ii][0];
		end += words[ii][3];
	}
	head += '\0'; end += '\0';					//����β�ַ��ֱ𹹽������ַ���

	int *flag = new int[word_num];
	for (ii = 0; ii < word_num; ii++)
		flag[ii] = 0;

	int head_count = 0, last_head = -1;
	for (ii = 0; ii < word_num; ii++) {
		char head_now = head[ii];
		kk = 0;

		do {
			jj = end.find(head_now, kk);
			if (jj == (-1)) {
				head_count++;					//�Ҳ�����֮��ӵ�β��
				last_head = ii;
			}
			else if ((jj == ii) || (flag[jj] != 0)) {
				kk = jj + 1;					//�ҵ��˷Ƿ���β��(�Լ��Ļ��ѱ�ռ�õ�)
			}
			else {
				flag[jj] = ii + 1;				//�ҵ��˺Ϸ���β����������ǰͷ����Ѱ�ң�������Ӧ�ı�־λ��������(�Լ�������ֵ+1)
				break;
			}
		} while ((-1) != jj);
	}

	if (head_count > 1)							//�ж��ͷ�����ERROR
		cout << "ERROR" << endl;
	else if (head_count == 0)					//û��ͷ�����CIRCLE
		cout << "CIRCLE" << endl;
	else {										//��Ψһͷ������ɹ�
		ii = last_head;
		cout << words[last_head].c_str();
		while (flag[ii]) {
			cout << ' ' << words[flag[ii] - 1].c_str();
			ii = flag[ii] - 1;
		}
		cout << endl;
	}

	delete[] flag;

	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<string>
#include<iostream>
#include<map>

using namespace std;


int parent[1000001];
vector<string> sameGroup[1000001];

string input;
map<string, int> str2int;
vector<string> int2str;

vector<pair<int, int>> same;
vector<pair<int, int>> diff;

string tempS[2];

int parsingScnt = 0;
bool isDiff;

bool hasNum[1000001];

string ans;


int ufind(int idx) {
	if (parent[idx] < 0)
		return idx;
	return parent[idx] = ufind(parent[idx]);
}

void uMerge(int a, int b) {
	a = ufind(a);//������ ��Ʈ
	b = ufind(b);

	if (a == b)
		return;
	parent[a] = b;
}


int main() {
	memset(parent, -1, sizeof(parent));
	cin >> input;
	input += "&&";

	for (int i = 0; i < input.size(); i++) {
		if (input[i] != '=' && input[i] != '&' && input[i] != '!') {
			tempS[parsingScnt].push_back(input[i]);//��ġ �к��� ���Ͽ�
		}
		else if (parsingScnt == 0) {
			isDiff = (input[i] == '!');//!= ���� �Ľ̵Ǵ� ����
			parsingScnt = 1;
			i++;
		}
		else {
			int pos1IDX;
			int pos2IDX;
			if (str2int.count(tempS[0])) {
				pos1IDX = str2int[tempS[0]];
			}
			else {
				str2int[tempS[0]] = int2str.size();
				pos1IDX = int2str.size();
				int2str.push_back(tempS[0]);
			}

			if (str2int.count(tempS[1])) {
				pos2IDX = str2int[tempS[1]];
			}
			else {
				str2int[tempS[1]] = int2str.size();
				pos2IDX = int2str.size();
				int2str.push_back(tempS[1]);
			}
			//�ߺ��� ����� ���Ͽ� map�� ���Ͽ� ��ġȮ�� �� ó��
			if (!isDiff) {
				same.push_back({ pos1IDX, pos2IDX });
			}
			else {
				diff.push_back({ pos1IDX, pos2IDX });
			}
			//������ 2���� �������� ����� ó�� ���� �׷� �ٸ� �׷�
			tempS[0] = "";
			tempS[1] = "";
			parsingScnt = 0;
			i++;
			//���� ������ �Ľ��ϱ� ���Ͽ� �ʱ�ȭ
		}

	}
	for (int i = 0; i < same.size(); i++) {
		uMerge(same[i].first, same[i].second);//==�׷쿡 �ִ� ģ������ ���� merge �������� 
	}
	for (int i = 0; i < int2str.size(); i++) {
		sameGroup[ufind(i)].push_back(int2str[i]);//�� �θ�(��Ʈ)�� ���Ϳ� �ڽĵ��� �־�����.... ��Ʈ���� ���Ͽ� ���ε�� ���� Ʈ���� ������ֱ�
	}

	for (int i = 0; i < int2str.size(); i++) {
		int cntNum = 0;
		for (int j = 0; j < sameGroup[i].size(); j++) {
			if (isdigit(sameGroup[i][j][0]) || sameGroup[i][j][0] == '-')
				cntNum++;
		}
		if (cntNum >= 2) {
			cout << "1==2\n";
			return 0;
		}//���� �׷쿡 ���ڰ� 2����� ���� ������ �ߺ��� ó������� ������ �ٸ� ���� 2���� ����ִٴ� ��
		if (cntNum == 1) {
			hasNum[i] = true;

		}//���� ǥ��
		if (sameGroup[i].size() < 2)
			continue;
		//Ʈ���� 1���ų� ���� ���� ��ŵ~
		int minLen = sameGroup[i][0].size();
		int minIDX = 0;
		for (int j = 1; j < sameGroup[i].size(); j++) {
			if (sameGroup[i][j].size() < minLen){
			minLen = sameGroup[i][j].size();
			minIDX = j;
			}
		}//Ʈ������ ���� ª�� ��Ʈ���� ã��

		string temp = sameGroup[i][minIDX];
		for (int j = 0; j < sameGroup[i].size(); j++) {
			if (j == minIDX)
				continue;
			ans += sameGroup[i][j] + "==" + temp + "&&";
		}//��Ʈ�� + ª�� ��Ʈ�� �������� ��������� ������.

		swap(sameGroup[i][0], sameGroup[i][minIDX]);
			//Ʈ���� ��Ʈ�� ���� ª�� ��Ʈ������ ���������
	}
	set<pair<int, int>> diffGroup;
	for (int i = 0; i < diff.size(); i++) {
		int pos1IDX = ufind(diff[i].first);
		int pos2IDX = ufind(diff[i].second);

		if (pos1IDX == pos2IDX) {
			cout << "1==2\n";
			return 0;
		}//�ٸ� �׷��� ģ���� �������Ǿ� �ִٴ� ���� �ᱹ ==���ÿ� !=��� �� -----> false
		if (hasNum[pos1IDX] && hasNum[pos2IDX])
			continue;//2���� ������ ���� ���δٸ� �� �� �̹Ƿ� �� �׻� true�̹Ƿ� ��ŵ
		diffGroup.insert({ min(pos1IDX, pos2IDX), max(pos1IDX, pos2IDX) });//�ߺ��� ó�����ֱ� ���Ͽ� set�� �־��ش�.
	}
	for (set<pair<int, int>> ::iterator it = diffGroup.begin(); it != diffGroup.end(); it++) {
		int pos1IDX = (*it).first;
		int pos2IDX = (*it).second;
		ans += sameGroup[pos1IDX][0] + "!=" + sameGroup[pos2IDX][0] + "&&";
	}
	if (ans.empty()) {
		cout << "1==1\n";
		return 0;
	}//������ ��Ȯ���� ��쿡�� ans�� �ٿ��ִ� ����̹Ƿ� ans�� ����� �ִٴ� ���� �׻� true
	//false�� ������ ó��
	ans.pop_back();
	ans.pop_back();
	cout << ans << "\n";
	return 0;
}
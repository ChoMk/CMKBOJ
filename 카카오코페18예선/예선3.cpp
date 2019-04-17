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
	a = ufind(a);//각각의 루트
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
			tempS[parsingScnt].push_back(input[i]);//위치 분별을 위하여
		}
		else if (parsingScnt == 0) {
			isDiff = (input[i] == '!');//!= 경우로 파싱되는 논리식
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
			//중복을 지우기 위하여 map을 통하여 위치확인 후 처리
			if (!isDiff) {
				same.push_back({ pos1IDX, pos2IDX });
			}
			else {
				diff.push_back({ pos1IDX, pos2IDX });
			}
			//논리식을 2가지 집합으로 나누어서 처리 같은 그룹 다른 그룹
			tempS[0] = "";
			tempS[1] = "";
			parsingScnt = 0;
			i++;
			//다음 논리식을 파싱하기 위하여 초기화
		}

	}
	for (int i = 0; i < same.size(); i++) {
		uMerge(same[i].first, same[i].second);//==그룹에 있는 친구들을 전부 merge 시켜주자 
	}
	for (int i = 0; i < int2str.size(); i++) {
		sameGroup[ufind(i)].push_back(int2str[i]);//각 부모(루트)의 벡터에 자식들을 넣어주자.... 스트링을 유니온 파인드와 같은 트리로 만들어주기
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
		}//같은 그룹에 숫자가 2개라는 것은 위에서 중복을 처리해줬기 때문에 다른 숫자 2개가 들어있다는 뜻
		if (cntNum == 1) {
			hasNum[i] = true;

		}//숫자 표시
		if (sameGroup[i].size() < 2)
			continue;
		//트리가 1개거나 없는 경우는 스킵~
		int minLen = sameGroup[i][0].size();
		int minIDX = 0;
		for (int j = 1; j < sameGroup[i].size(); j++) {
			if (sameGroup[i][j].size() < minLen){
			minLen = sameGroup[i][j].size();
			minIDX = j;
			}
		}//트리에서 가장 짧은 스트링을 찾자

		string temp = sameGroup[i][minIDX];
		for (int j = 0; j < sameGroup[i].size(); j++) {
			if (j == minIDX)
				continue;
			ans += sameGroup[i][j] + "==" + temp + "&&";
		}//스트링 + 짧은 스트링 형식으로 논리연산식을 붙이자.

		swap(sameGroup[i][0], sameGroup[i][minIDX]);
			//트리의 루트를 가장 짧은 스트링으로 만들어주자
	}
	set<pair<int, int>> diffGroup;
	for (int i = 0; i < diff.size(); i++) {
		int pos1IDX = ufind(diff[i].first);
		int pos2IDX = ufind(diff[i].second);

		if (pos1IDX == pos2IDX) {
			cout << "1==2\n";
			return 0;
		}//다른 그룹의 친구가 머지가되어 있다는 뜻은 결국 ==동시에 !=라는 뜻 -----> false
		if (hasNum[pos1IDX] && hasNum[pos2IDX])
			continue;//2개가 숫자인 경우는 서로다른 두 수 이므로 즉 항상 true이므로 스킵
		diffGroup.insert({ min(pos1IDX, pos2IDX), max(pos1IDX, pos2IDX) });//중복을 처리해주기 위하여 set에 넣어준다.
	}
	for (set<pair<int, int>> ::iterator it = diffGroup.begin(); it != diffGroup.end(); it++) {
		int pos1IDX = (*it).first;
		int pos2IDX = (*it).second;
		ans += sameGroup[pos1IDX][0] + "!=" + sameGroup[pos2IDX][0] + "&&";
	}
	if (ans.empty()) {
		cout << "1==1\n";
		return 0;
	}//연산이 불확실한 경우에만 ans에 붙여주는 방식이므로 ans가 비워져 있다는 것은 항상 true
	//false는 위에서 처리
	ans.pop_back();
	ans.pop_back();
	cout << ans << "\n";
	return 0;
}
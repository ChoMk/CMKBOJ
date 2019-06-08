#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

vector<int>result;
int n;
string temp;
int kbs1idx;
int kbs2idx;

int main() {
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == "KBS1") {
			kbs1idx = i;
		}else if (temp == "KBS2") {
			kbs2idx = i;
		}
	}
	int addCnt = 0;
	if (kbs1idx > kbs2idx) {
		addCnt = 1;
	}
	for (int i = 0; i < kbs1idx; i++) {
		cout << "1";
	}
	for (int i = 0; i < kbs1idx; i++) {
		cout << "4";
	}
	for (int i = 0; i < kbs2idx + addCnt; i++) {
		cout << "1";
	}
	for (int i = 0; i < kbs2idx + addCnt - 1; i++) {
		cout << "4";
	}
	//우선 1채널은 무조건 첫번째로 옮겨주고 (위치를 찾고 그 위치만큼 이동 후 내려오고)
	//2채널은 자신 뒤에 1채널이 있었으면 1채널이 앞으로 가면서 자신보다 앞에 있는 채널의 수가 1개 늘어나게 된다
	//이를 고려하여 addCnt로 처리해주고
	//2채널은 1채널 바로 위까지 그러니깐 2번째까지만 이동하자
	cout << "\n";
}
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
	//�켱 1ä���� ������ ù��°�� �Ű��ְ� (��ġ�� ã�� �� ��ġ��ŭ �̵� �� ��������)
	//2ä���� �ڽ� �ڿ� 1ä���� �־����� 1ä���� ������ ���鼭 �ڽź��� �տ� �ִ� ä���� ���� 1�� �þ�� �ȴ�
	//�̸� ����Ͽ� addCnt�� ó�����ְ�
	//2ä���� 1ä�� �ٷ� ������ �׷��ϱ� 2��°������ �̵�����
	cout << "\n";
}
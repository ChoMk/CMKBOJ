#include <iostream>
#include <algorithm>
#include <vector>
#define END 1000000000
using namespace std;
int N, lp, rp, ans;

vector<pair<int, int>> vt;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt.push_back({ a,b });
	}
	sort(vt.begin(), vt.end());

	//lp = rp = -END;
	lp = vt[0].first;
	rp = vt[0].second;

	for (int i = 1; i < N; i++) {
		if (rp < vt[i].first) {
			ans += rp - lp;
			lp = vt[i].first;
			rp = vt[i].second;
		}//�������� ��� ����
		else rp = max(rp, vt[i].second);// �ƴѰ�� �������� �÷�����
	}
	ans += rp - lp;//�÷��ִٰ� ������ ���ʿ��� ������ ���� �Ÿ� �����ֱ�
	printf("%d\n", ans);
	return 0;
}
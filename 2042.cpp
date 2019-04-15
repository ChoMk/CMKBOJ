#include<cstdio>

using namespace std;
long long arr[1000001];
long long tree[4000004];

int n, m, k;
int a, b;


long long makeTree(int start, int end, int pos) {
	if (start == end) {
		return tree[pos] = arr[start];
	}
	
	return tree[pos] = makeTree(start, (start+end)/2, pos * 2) + makeTree((start+end)/2 + 1, end, pos * 2 + 1);
}

long long sumTree(int left, int right, int start, int end, int pos) {
	if (left>end || right<start) {
		return 0;
	}//���� ��
	if (left <= start && end <= right) {
		return tree[pos];//������ ����
	}
	return (sumTree(left, right, start, (start + end) / 2, pos * 2) + sumTree(left, right, (end + start) / 2 + 1, end, pos * 2 + 1));
	//������ ��ġ�� ���
}//start, end�� ��� ���� ����...

void changeTree(int idx, long long d, int start, int end, int pos) {
	if (idx<start || idx>end) {
		return;
	}
	tree[idx] += d;
	if (start != end) {
		changeTree(idx, d, start, (end+start)/2, pos * 2);
		changeTree(idx, d, (end + start) / 2 + 1, end, pos * 2 + 1);
	}
}//idx�� ������ ��ġ, d�� ������ ��ŭ�� ũ��, s,e�� ���� ��ġ, pos�� Ʈ����ġ



int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	makeTree(0, n-1, 1);
	for (int i = 0; i < m + k; i++) {
		scanf("%d %d", &a, &b);
		if (a == 1) {
			long long c;
			scanf("%lld", &c);
			changeTree(b - 1, c - arr[b - 1], 0, n - 1, 1);
			arr[b - 1] = c;
		}
		else {
			int c;
			scanf("%d", &c);
			printf("%lld\n", sumTree(b - 1, c - 1, 0, n - 1, 1));
		}
	}

}
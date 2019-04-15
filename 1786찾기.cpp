#include <iostream>
#include <string>
#include <cstdio>
#include <vector>



using namespace std;
const int MAX = 1000000;
int fail[MAX] = { 0 };
int main() {
	string W, S;
	int M, N;
	getline(cin, S);
	getline(cin, W);
	N = S.length();
	M = W.length();

	for (int i = 1, j = 0; i<M; i++) {
		while (j > 0 && W[i] != W[j]) 
			j = fail[j - 1];
		if (W[i] == W[j]) 
			fail[i] = ++j;
	}


	// S, W�� ��ġ�ϴ� ������ result�� ����
	vector<int> result;
	for (int i = 0, j = 0; i<N; i++) {
		// ���� ���ڰ� ����ġ�ϸ� fail ���� ��� ����
		while (j > 0 && S[i] != W[j]) j = fail[j - 1];
		// ���� ���ڰ� ��ġ
		if (S[i] == W[j]) {
			// W�� S[i:i+M-1]���� ã��
			if (j == M - 1) {
				// i=0���� �����Ѵٸ� i-M+1. ���� ���ǿ� ���� 1�� ����
				result.push_back(i - M + 2);
				// ã�� ���� ��ó�� j�� �̵���Ű�� ��
				j = fail[j];
			}
			else j++;
		}
	}

	// ��� ���
	printf("%d\n", result.size());
	for (int i : result)
		printf("%d ", i);
}


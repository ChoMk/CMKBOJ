#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int n;
int k;
int dp[42][2][2][2];//�� ��ġ �ڽ�, �ڽ� ���� �������
int fun(int idx, int letfEmpty, int midEmpty, int kEmpty) {
	if (idx == n + 1)
		return 1;
	int &reg = dp[idx][letfEmpty][midEmpty][kEmpty];
	if (reg != -1)
		return reg;
	reg = 0;
	int nextIDX = idx + 1;
	
	if (idx == k) {
		return reg = fun(nextIDX, kEmpty, 0, kEmpty);
		
	}
	else {
		if (idx != n && idx +1 != k) {//���������� ������ ��ä��, k�� k���¸� ���� �ڿ��� ����
			
			reg += fun(nextIDX, midEmpty, 1, kEmpty);//������ ä��
		}
				
		
		if (letfEmpty == 0 && idx-1 != k) {//k�� k���¸� ���� �ڿ��� ����
			
			reg += fun(nextIDX, midEmpty, 0, kEmpty);//���� ä��

		
			
		}
		if (midEmpty == 0) {//�̵尡 k�� ����� ���� ����
			
			reg += fun(nextIDX, 1, 0, kEmpty);//�̵�ä��
			
			
		}
		if (kEmpty == 0) {
			
			reg += fun(nextIDX, midEmpty, 0, 1);//kä��
			
			
		}
	}
	
	return reg;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	scanf("%d", &k);
	printf("%d\n", fun(1, 1, 0, 0));//0 = �ڱ���ġ, 1 = ����, 2 = �߰�, 3 = ������
	
}
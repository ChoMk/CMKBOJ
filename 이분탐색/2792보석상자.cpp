#include <cstdio>
using namespace std;

int main() {
	int N, M, A[300000];
	scanf("%d %d", &N, &M);
	for (int i = 0; i<M; i++)
		scanf("%d", A + i);
	int lo = 0, hi = 1e9;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i<M; i++)
			sum += (A[i] - 1) / mid + 1;
		(sum <= N ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}

//문제에서 예제로가 생각하는 것이 아니라
//최대로 많은 학생들에게 보석을 나누어 주는 경우, 그때 보석을 나누어 줄때 최대로 나누어 줄 수 있는 보석으로 나누어주자
//3 3 1 3 1 
//
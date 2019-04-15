#include <cstdio>
#include <cstring>
using namespace std;

int pi[1000000], j;

int main() {
	while (1) {
		
		char S[1000001];
		memset(pi, 0, sizeof(pi));
		j = 0;
		
		scanf("%s", S);
		
		if (S[0] == '.') break;
		
		int N = strlen(S);

		for (int i = 1; i<N; i++) {
			while (j > 0 && S[i] != S[j]) j = pi[j - 1];
			if (S[i] == S[j]) pi[i] = ++j;
		}//fail함수 만들기
		//pi[len]은 반복되는 문자열의 길이가 반복될 수 있는 최대 길이를 의미한다.
		int q = pi[N - 1], r = N - q;//len - pi[len]이 문자열에서 반복되는 부분문자열의 최소 길이이다.
		if (q == 0 || q % r != 0) puts("1");
		else printf("%d\n", q / r + 1);
	}
}	
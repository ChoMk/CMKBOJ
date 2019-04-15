#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

long long n;

long long arr[6];

long long savePair[6] = {5, 4, 3, 2, 1, 0};//주사위 반대편
long long result;


long long searchMinBottonSpace(long long fc, long long sc, long long tc) {
	long long space = 0;
	space += n * n*fc;//가장 많이 노출되는 면에서 최소로 도배
	
	space += 2 * (sc + tc);
	space += sc*(n-2);
	space += sc*(n - 1) * 2;
	return space;
}
long long searchMinSideSpace(long long fc, long long tc) {
	long long space = 0;
	space += n *fc;//가장 많이 노출되는 면에서 최소로 도배
	
	space += 2 * (tc);
	
	space += fc*(n-1) * 2;
	return space;
}


int main() {
	scanf("%lld", &n);
	for (int i = 0; i < 6; i++) {
		scanf("%lld", &arr[i]);
	}
	if (n == 1) {
		
		sort(arr, arr + 6);
		for (int i = 0; i < 5; i++) {
			result += arr[i];
		}
		printf("%lld\n", result);
		return 0;
	}
	arr[0] = min(arr[0], arr[5]);
	arr[1] = min(arr[1], arr[4]);
	arr[2] = min(arr[2], arr[3]);
	long long fc;
	long long sc;
	long long tc;
	sort(arr, arr + 3);
	fc = arr[0];
	sc = arr[1];
	tc = arr[2];
	result += searchMinBottonSpace(fc, sc, tc)*2;
	result += searchMinSideSpace(fc, sc)*(n-2);
	printf("%lld\n", result);

}
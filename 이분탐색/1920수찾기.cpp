#include<cstdio>
#include<algorithm>

using namespace std;

int arr[100001];
int n;
int m;
int a;
int bs(int left, int right, int val) {
	if (left == right)
		return 0;
	int mid = (left + right) / 2;
	if (arr[mid] == val)
		return 1;
	else if(arr[mid]<val)
	{
		return bs(mid + 1, right, val);
	}
	else {
		return bs(left, mid, val);
	}

}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		printf("%d\n", bs(0, n, a));
	}
}

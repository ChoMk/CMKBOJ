#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;



int n;
int arr[101];
int result;


bool fun(int idx) {
	int fscore = 0;
	int sscore = 0;
	bool temp1 = true;
	bool temp2 = true;
	int i = idx;


	if (n % 2 == 1) {
		while (true) {
			fscore += arr[i] % 2;
			sscore += arr[(i + 1) % n] % 2;
			i = i + 2;
			i %= n;
			if (i == (idx - 1 + n) % n)
				break;
		}
		fscore += arr[(idx - 1 + n) % n] % 2;
	}
	else {
		while (true) {
			fscore += arr[i] % 2;
			sscore += arr[(i + 1) % n] % 2;
			i = i + 2;
			i %= n;
			if (idx == i)
				break;
		}
	}

	if (fscore < sscore)
		temp1 = false;
	fscore = 0;
	sscore = 0;
	i = idx;

	if (n % 2 == 1) {
		while (true) {
			fscore += arr[i] % 2;
			sscore += arr[(i - 1 + n) % n] % 2;
			i = i - 2;
			i += n;
			i %= n;
			if (i == (idx + 1) % n)
				break;
		}
		fscore += arr[(idx + 1) % n] % 2;
	}
	else {
		while (true) {
			fscore += arr[i] % 2;
			sscore += arr[(i - 1 + n) % n] % 2;
			i = i - 2;
			i += n;
			i %= n;
			if (idx == i)
				break;
		}
	}

	if (fscore < sscore)
		temp2 = false;
	if (temp1 == false && temp2 == false)
		return false;
	return true;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	if (n == 1) {
		if (arr[0] % 2 == 1)
			printf("1\n");
		else
			printf("0\n");
		return 0;
	}


	for (int i = 0; i < n; i++) {
		if (fun(i))
			result++;
	}
	printf("%d\n", result);


}
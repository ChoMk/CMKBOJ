#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<char> comp;
int n, k;
char num[500001];

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", &num);
	comp.push_back(num[0]);
	int cntK = 0;
	for (int i = 1; i < n; i++) {
		while (true) {
			if (comp.empty()) {
				comp.push_back(num[i]);
				break;
			}
			int tempTop = comp[comp.size() - 1]-'0';
			if (tempTop >= num[i]-'0') {
				comp.push_back(num[i]);
				break;
			}
			else if(cntK != k){
				cntK++;
				comp.pop_back();
			}
			else {
				comp.push_back(num[i]);
				break;
			}
		}
		
	}

	for (int i = 0; i < n - k; i++) {
		printf("%c", comp[i]);
	}
	printf("\n");
}

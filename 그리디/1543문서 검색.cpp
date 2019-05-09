#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

int dp[3000];
string arr;
string comp;

int fun(int idx) {
	if (arr.size() < idx+comp.size())
		return 0;
	int &reg = dp[idx];
	if (reg != -1)
		return reg;
	reg = 0;
	bool flag = true;

	for (int i = 0; i < comp.size(); i++) {
		if (arr[idx + i] != comp[i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		reg = fun(idx + comp.size())+1;
	}
	reg = max(reg, fun(idx + 1));
	return reg;
	
}

int main() {
	memset(dp, -1, sizeof(dp));
	getline(cin, arr);
	
	getline(cin, comp);
	printf("%d\n", fun(0));
}


/*
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
char doc[2501], word[51];
gets(doc);
gets(word);
int H = strlen(doc);
int N = strlen(word);
int result = 0;
for(int i=0; i<=H-N;){
bool find = true;
for(int j=0; j<N; j++)
if(doc[i+j] != word[j]){
find = false;
break;
}
if(find){
result++;
i += N;
}
else i++;
}
printf("%d\n", result);
}
*/

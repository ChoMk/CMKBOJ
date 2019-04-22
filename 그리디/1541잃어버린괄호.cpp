#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


string temp;
vector<string> arr;

int fun(int curidx, int minusflag) {
	if (curidx == arr.size())
		return 0;
	int result = 999999999;
	if (arr[curidx] == "+") {
		if (minusflag == 0) {
			result = min(stoi(arr[curidx + 1])+fun(curidx+2, 0), result);//기존 유지
		}
		else {
			result = min(-stoi(arr[curidx + 1]) + fun(curidx + 2, 1), result);//-괄호 수용
			result = min(stoi(arr[curidx + 1]) + fun(curidx + 2, 0), result);//-괄호 거부
		}
		
	}
	else {
		if (minusflag == 0) {
			result = min(-stoi(arr[curidx + 1]) + fun(curidx + 2, 1), result);//새로운 -괄호
		}
		else {
			result = min(-stoi(arr[curidx + 1]) + fun(curidx + 2, 1), result);//새로운 -괄호
			result = min(stoi(arr[curidx + 1]) + fun(curidx + 2, 1), result);//기존 -괄호 수용
		}
	}
	return result;
}

int main() {
	cin >> temp;
	int idx = 0;
	int preidx = 0;
	while (true) {
		if (idx == temp.size()) {
			arr.push_back(temp.substr(preidx, idx - preidx));
			break;
		}
			

		if (temp[idx] == '+' || temp[idx] == '-') {
			arr.push_back(temp.substr(preidx, idx - preidx));
			arr.push_back(temp.substr(idx, 1));
			idx++;
			preidx = idx;
		}
		idx++;
	}
	printf("%d", stoi(arr[0]) + fun(1, 0));
	return 0;
}
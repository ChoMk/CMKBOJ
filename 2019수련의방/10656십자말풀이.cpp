#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int n, m;
char arr[52][52];
vector<pair<int, int>> result;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (((i - 1 < 0 || arr[i - 1][j] == '#') && arr[i][j] == '.'&&i + 2 < n&&arr[i + 1][j] == '.'&&arr[i + 2][j] == '.')) {
				result.push_back({ i + 1,j + 1 });
			}else if(((j - 1 < 0 || arr[i][j-1] == '#') && arr[i][j] == '.'&&j + 2 < m&&arr[i][j+1] == '.'&&arr[i][j+2] == '.')) {
				result.push_back({ i + 1,j + 1 });
			}
		}
	}
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i].first << " " << result[i].second << "\n";
	}

}
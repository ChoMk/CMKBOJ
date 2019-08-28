#include <string>
#include <vector>
#include<algorithm>

using namespace std;

char Board[32][32];//Y´Â ºó °ø°£
int N, M;

int checkRemove() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Board[i][j] == 'Y')
				result++;
		}
	}
	return result;
}

int checkScore() {
	vector<pair<int, int>> checkY;
	int score = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (Board[i][j] != 'Y') {
				if (Board[i][j] == Board[i][j + 1] && Board[i][j] == Board[i + 1][j] && Board[i][j] == Board[i + 1][j + 1]) {
					score++;
					checkY.push_back({ i,j });
				}
			}
		}
	}
	for (int i = 0; i < checkY.size(); i++) {
		int curI = checkY[i].first;
		int curJ = checkY[i].second;

		Board[curI][curJ] = 'Y';

		Board[curI+1][curJ+1] = 'Y';

		Board[curI+1][curJ] = 'Y';

		Board[curI][curJ+1] = 'Y';
	}

	return score;
}

void downMap() {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 0; j--) {
			char tempChar = Board[i][j];
			if (tempChar == 'Y') {
				int upIDXN = i - 1;
				while (true) {
					if (upIDXN < 0)
						break;
					if (Board[upIDXN][j] != 'Y') {
						swap(Board[i][j], Board[upIDXN][j]);
						Board[upIDXN][j];
						break;
					}
					upIDXN--;
				}
			}
		}
	}

}


int solution(int m, int n, vector<string> board) {
	N = m;
	M = n;

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Board[i][j] = board[i][j];
		}
	}
	while (true) {
		int tempScore = checkScore();
		if (tempScore == 0)
			break;
		downMap();
		
	}
	return answer = checkRemove();
}
int main() {
	vector<string> arr;
	arr.push_back("CCBDE");

	arr.push_back("AAADE");

	arr.push_back("AAABF");

	arr.push_back("CCBBF");
	solution(4, 5, arr);
}
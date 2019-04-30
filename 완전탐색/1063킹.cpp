#include<iostream>
#include<string>

using namespace std;

int n;
string kIDX;
string sIDX;
int kX;
int kY;
int sX;
int sY;
string state;

int main() {
	cin >> kIDX >> sIDX >> n;
	kX = kIDX[0] - 'A';
	kY = kIDX[1] - '1';
	sX = sIDX[0] - 'A';
	sY = sIDX[1] - '1';

	for (int i = 0; i < n; i++) {
		cin >> state;
		int preKx = kX;
		int preKy = kY;
		int preSx = sX;
		int preSy = sY;
		
		if (state == "R") {
			kX++;
			
		}
		else if (state == "L") {
			kX--;
			
		}
		else if (state == "B") {
			kY--;
			
		}
		else if (state == "T") {
			kY++;
			
		}
		else if (state == "RT") {
			kY++;
			
			kX++;
			
		}
		else if (state == "LT") {
			kX--;
			
			kY++;
			
		}
		else if (state == "RB") {
			kX++;
			
			kY--;
			
		}
		else if (state == "LB") {
			kY--;
			
			kX--;
			
		}
		if (kX == sX && kY == sY) {
			if (state == "R") {
				sX++;

			}
			else if (state == "L") {
				sX--;

			}
			else if (state == "B") {
				sY--;

			}
			else if (state == "T") {
				sY++;

			}
			else if (state == "RT") {
				sY++;

				sX++;

			}
			else if (state == "LT") {
				sX--;

				sY++;

			}
			else if (state == "RB") {
				sX++;

				sY--;

			}
			else if (state == "LB") {
				sY--;

				sX--;

			}
		}
		if (kX > 7 || kX < 0 || kY>7 || kY < 0 || sX>7 || sX < 0 || sY>7 || sY < 0) {
			kX = preKx;
			kY = preKy;
			sX = preSx;
			sY = preSy;
		}
	}
	cout << (char)('A' + kX) << (char)('1' + kY) <<"\n";
	cout << (char)('A' + sX) << (char)('1' + sY) <<"\n";
}
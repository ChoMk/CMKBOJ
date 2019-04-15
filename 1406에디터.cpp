#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
	int n;
	string s; //초기 입력 문자열

	cin >> s; //abcd
	cin >> n;

	list<char> editor(s.begin(), s.end()); // 문자열을 리스트로  
	auto cursor = editor.end(); // 초기 커서의 위치는 문장의 맨 뒤

	while (n--) {// 명령의 수 만큼 반복 
		char cmd;
		cin >> cmd; //명령어 입력 

		if (cmd == 'L') {
			if (cursor != editor.begin()) {
				cursor--;
			}
		}
		else if (cmd == 'D') {
			if (cursor != editor.end()) {
				cursor++;
			}
		}
		else if (cmd == 'B') {
			if (cursor != editor.begin()) {
				auto tempCursor = cursor;
				cursor--;
				editor.erase(cursor);
				cursor = tempCursor;
			}
		}
		else if (cmd == 'P') {
			char x;
			cin >> x;
			editor.insert(cursor, x);
		}
	}
	for (auto &x : editor) {
		cout << x;
	}
	cout << "\n";
	return 0;
}

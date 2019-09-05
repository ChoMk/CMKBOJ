#include <string>
#include <vector>
#include<map>
#include<cstring>

using namespace std;

map<string, int> checkWordCnt;
struct Trie {
	bool finish;    //끝나는 지점을 표시해줌
	Trie* next[26];    //26가지 알파벳에 대한 트라이
	int cnt[26];
	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
		memset(cnt, 0, sizeof(cnt));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0')
			finish = true;    //문자열이 끝나는 지점일 경우 표시
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL)
				next[curr] = new Trie();    //탐색이 처음되는 지점일 경우 동적할당
			next[curr]->insert(key + 1);    //다음 문자 삽입
			cnt[curr]++;
		}
	}
	int find(const char* key) {
		if (*key == '\0')
			return 0;
		int curr = *key - 'A';
		if (cnt[curr] == 1)
			return 0;
		if (next[curr] == NULL)
			return NULL;//찾는 값이 존재하지 않음
		return next[curr]->find(key + 1)+1; //다음 문자를 탐색
	
	}

};


void checkWordFunction(string word, Trie * trie) {
	char word_char[1000001];
	for (int i = 0; i < word.size(); i++) {
		word_char[i] = word[i];
	}
	word_char[word.size()] = '\0';
	trie->insert(word_char);
	return;
}
int AutomaticCompletionCnt(string word, Trie * trie) {
	char word_char[1000001];
	for (int i = 0; i < word.size(); i++) {
		word_char[i] = word[i];
	}
	word_char[word.size()] = '\0';
	
	return trie->find(word_char);
}


int solution(vector<string> words) {
	Trie *root = new Trie;
	int answer = 0;
	for (int i = 0; i < words.size(); i++) {
		checkWordFunction(words[i],  root);
	}
	for (int i = 0; i < words.size(); i++) {
		answer += AutomaticCompletionCnt(words[i], root);
	}
	return answer;
}
int main() {
	vector<string> temp;
	temp.push_back("go");
	temp.push_back("gone");
	temp.push_back("guild");
	solution(temp);
}
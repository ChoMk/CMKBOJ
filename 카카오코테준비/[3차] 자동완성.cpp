#include <string>
#include <vector>
#include<map>
#include<cstring>

using namespace std;

map<string, int> checkWordCnt;
struct Trie {
	bool finish;    //������ ������ ǥ������
	Trie* next[26];    //26���� ���ĺ��� ���� Ʈ����
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
			finish = true;    //���ڿ��� ������ ������ ��� ǥ��
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL)
				next[curr] = new Trie();    //Ž���� ó���Ǵ� ������ ��� �����Ҵ�
			next[curr]->insert(key + 1);    //���� ���� ����
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
			return NULL;//ã�� ���� �������� ����
		return next[curr]->find(key + 1)+1; //���� ���ڸ� Ž��
	
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
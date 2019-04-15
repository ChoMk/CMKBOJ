#include<cstdio>

using namespace std;

const int ALPHA = 26;
char str[501];
int n, m;



class TrieNode {
	private:
		TrieNode * children[ALPHA];
		bool check;
public:
	TrieNode() {
		for (int i = 0; i < ALPHA; i++) {
			children[i] = nullptr;
		}
		check = false;
	}
	~TrieNode(){
		for (int i = 0; i < ALPHA; i++) {
			if (children[i]) delete children[i];
		}
	}

	void insert(const char* key) {
		if (*key == NULL) {
			check = true;
			return;
		}
		else {
			int next = (*key) - 'a';
			if (children[next] == nullptr) {
				children[next] = new TrieNode();
			}
			children[next]->insert(key + 1);
		}
	}
	bool isCheck(const char * key) {
		if (*key == NULL && check == true) {
			return true;
		}
		else {
			int next = (*key) - 'a';
			if (children[next] == nullptr) {
				return false;
			}
			return children[next]->isCheck(key + 1);
		}
	}
};
int result;
int main() {
	TrieNode *root = new TrieNode();
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", &str);
		root->insert(str);
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", &str);
		if (root->isCheck(str)) {
			result++;
		}
	}
	printf("%d\n", result);
}
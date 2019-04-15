#include<cstdio>

using namespace std;

const int ALPHA = 10;
char str[501];
char saveStr[10000][501];
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
	~TrieNode() {
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
			int next = (*key) - '0';
			if (children[next] == nullptr) {
				children[next] = new TrieNode();
			}
			children[next]->insert(key + 1);
		}
	}
	bool isCheck(const char * key) {
		if (*key == NULL) {
			return true;
		}
		else {
			int next = (*key) - '0';
			if (check == true)
				return false;
			return children[next]->isCheck(key + 1);
		}
	}
};
int result;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		TrieNode *root = new TrieNode();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", &saveStr[i]);
			root->insert(saveStr[i]);
		
		}
		int sw = 0;
		for (int i = 0; i < n; i++) {
			if (root->isCheck(saveStr[i])) {
				continue;
			}
			else {
				sw = 1;
				printf("NO\n");
				break;
			}
		}
		if(sw == 0)
			printf("YES\n");
	}
	
}
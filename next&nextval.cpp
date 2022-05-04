#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
char s[1000];
int next[1000];
void getnext(int len) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < len) {
		if (j == 0 || s[i] == s[j]) {
			++i, ++j;
			next[i] = j;
		} else j = next[j];
	}
	for (int i = 1; i <= len; i++) cout << next[i] << " ";
	cout << endl;
}

void getnextval(int len) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < len) {
		if (j == 0 || s[i] == s[j]) {
			++i, ++j;
			if (s[i] != s[j])next[i] = j;
			else next[i] = next[j];
		} else j = next[j];
	}
	for (int i = 1; i <= len; i++) cout << next[i] << " ";
	cout << endl;
}
int main() {
	while (scanf("%s", s + 1)) {
		int len = strlen(s + 1);
		getnext(len);
		getnextval(len);
	}
}

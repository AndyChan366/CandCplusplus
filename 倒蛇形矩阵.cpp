#include <iostream>
using namespace std;
int main() {
	int n = 0, i = 0, r = 1;
	cin >> n;
	int number[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			number[i][j] = 0;
		}
	}
	while(i < n - 1 -i) {
		for(int j = i; j < n-i; j++) {
			number[j][n-i-1] = r;
			r++;
		}
		for(int j = n-i-2; j >=i; j--) {
			number[n-i-1][j] = r;
			r++;
		}
		for(int j =  n-i-2; j>=i; j--){
			number[j][i] = r;
			r++;
		}
		for(int j = i+1; j <= n-i-2; j++) {
			number[i][j] = r;
			r++;
		}
		i++;
	}
	if(i == n-i-1) {
		number[i][i] = n*n;
	} 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << number[i][j] << ' ';
		}
		cout << '\n';
	}
}


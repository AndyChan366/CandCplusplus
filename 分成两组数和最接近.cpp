#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 120;

int w[M];
int dp[M*100];
bool bools[M][M];


int main()
{
    int n,i,j,k,h;
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &w[i]);
            sum += w[i];
        }
        memset(dp, 0, sizeof(dp));
        memset(bools, 0, sizeof(bools));
        for (int i = 0; i < n; ++i){ 
            for (int j = sum/2; j >= w[i]; --j) {
                if (dp[j] < dp[j-w[i]] + w[i]) {
                    dp[j] = dp[j-w[i]] + w[i];
                    bools[i][j] = true;
                }
            }
            } 
        printf("%d\n", sum - dp[sum/2]*2);
        i = n;
        j = sum/2;
        while (i--) {
            if (bools[i][j]) {
                    printf("%d ", w[i]);
					j -= w[i];
            }
        }
    }
    return 0;
    
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 21
static int max(int a, int b){ return a>b?a:b;}
static int map[M];
static int seq[M];

static int dp[M][M];
static void solve(void){
	int n, x, i, j;
	scanf("%d%d", &n, &x);
	map[x-1] = 0;
	for(i=1; i<n; ++i){
		scanf("%d", &x);
		map[x-1] = i;
	}
	while(~scanf("%d", &x)){
		seq[x-1] = 0;
		for(i=1; i<n; ++i){
			scanf("%d", &x);
			seq[x-1] = i;
		}
		memset(dp ,0, sizeof(dp));
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				if(seq[i]==map[j]){
					dp[i+1][j+1] = dp[i][j]+1;
				}else{
					dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
				}
			}
		}
		printf("%d\n", dp[n][n]);
	}
}
#if OJ_TEST
	int main(int ac, char *av[]){
		solve();
		return 0;
	}
#elif  LOCAL_TEST
	void run(void){
		solve();
	}

#else

#endif

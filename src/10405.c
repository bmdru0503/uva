#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 1002
static int mx[M][M];
static char one[M], two[M];
static int max(int a, int b){ return a>b?a:b; }
static void solve(void){
	int i, j, m, n;
	while(gets(one)){
		gets(two);
		m = strlen(one); n = strlen(two);
		mx[0][0] = (one[0]==two[0]) ? 1:0;
		for(i=1; i<m; ++i){
			mx[i][0] = (one[i]==two[0])?1:mx[i-1][0];
		}
		for(i=1; i<n; ++i){
			mx[0][i] = (one[0]==two[i])?1:mx[0][i-1];
		}
		for(i=1; i<m; ++i){
			for(j=1; j<n; ++j){
				mx[i][j] = (one[i]==two[j]) ? (1+mx[i-1][j-1]):\
						max(mx[i][j-1],mx[i-1][j]);
			}
		}
		printf("%d\n", mx[m-1][n-1]);
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

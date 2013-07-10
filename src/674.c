#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 8000

static int charge[M][4]; /* charge[m][n] 表示钱数量为m, 硬币各类为n时方案 */
static int coin[] = {1, 5, 10,25, 50};
#define M_COIN (sizeof(coin)/sizeof(coin[0]))
static void init(void){
	int i, j;
	for(i=1; i<M; ++i) charge[i][0]=1;
	for(i=0; i<M_COIN; ++i) charge[0][i] = 1;
	for(i=1; i<M_COIN; ++i){
		for(j=1; j<M; ++j){
			charge[j][i] = charge[j][i-1] + \
					(j>=coin[i] ? charge[j-coin[i]][i] : 0);
		}
	}
}

static int charge2[M];
static void init2(void){
	int i, j;
	memset(charge2, 0, sizeof(charge2));
	charge2[0] = 1;
	for(i=0; i<M_COIN; ++i){
		for(j=coin[i]; j<M; ++j){
			charge2[j] +=  charge2[j-coin[i]];
		}
	}
}
static void solve(void){
	int n;
	init2();
	while(~scanf("%d", &n)){
		printf("%d\n", charge2[n]);
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

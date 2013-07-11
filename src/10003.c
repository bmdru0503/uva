#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 52
static int cuts[M][M];
static int pos[M];

static void solve(void){
	int end, n, i, j, k, ms, mt;
	while(scanf("%d", &end), end){
		scanf("%d", &n);
		pos[0] = 0;
		for(i=1; i<=n; ++i){
			scanf("%d", &pos[i]);
		}
		pos[++n] = end;
		for(i=0; i<n; ++i) cuts[i][i+1] = 0;
		for(k=1; k<n; ++k){ /* 两切割点中间切割点的数量 ,0和n为两端，其实未害割 */
			for(i=0; i<=n-k; ++i){
				for(ms=0x7fffffff, j=i+1; j<k+i+1; ++j){
					mt = cuts[i][j]+cuts[j][i+k+1] + pos[i+k+1]-pos[i];
					if(mt<ms) ms = mt;
				}
				cuts[i][i+k+1] = ms;
			}
		}

		printf("The minimum cutting is %d.\n", cuts[0][n]);

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

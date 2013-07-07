#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 0

static void solve(void){
	int n, ans, lm, cs=0;
	long long ta, tb;
	while(scanf("%d%d", &n, &lm)){
		if(n<0) break;
		for(ta=n, tb=lm, ans=1; ta!=1; ++ans){
			if(ta%2){
				ta =ta*3 +1;
				if(ta>tb) break;
			}else{
				ta /= 2;
			}
		}
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", \
				++cs, n, lm, ans);
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

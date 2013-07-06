#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 0

static void solve(void){
	int n, k;
	int left; /* butt counts */
	while(~scanf("%d%d", &n, &k)){
		left = n;
		while(left>=k){
			n += left/k;
			left = left%k + left/k;
		}
		printf("%d\n", n);
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

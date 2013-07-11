#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 1
#define M 10001
static int seg[M];

static void solve(void){
	int end, c1, c2, n, i, k, ms, mt, ans;
	while(scanf("%d", &end), end){
		scanf("%d", &n);
		for(c1=0, i=0; i<n; ++i){
			scanf("%d", &c2);
			seg[i] = c2-c1;
			c1 = c2;
		}
		seg[i] = end - c2;
		for(ans=0, c1=0, c2=n+1; c1<n; ++c1){
			for(ms=2000, i=0; i<c2-1; ++i){
				mt = seg[i]+seg[i+1];
				if(mt<ms){
					ms = mt; k=i;
				}
			}
			seg[k] = ms;
			ans += ms;
			for(i=k+1; i<c2-1; ++i) seg[i]=seg[i+1];
			--c2;
		}
		printf("The minimum cutting is %d.\n", ans);

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

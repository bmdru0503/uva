#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 1
#define M 0

static void solve(void){
	int b, p, m, i;
	long long t;
	while(~scanf("%d%d%d", &b, &p, &m)){
		for(t=1, i=0; i<p; ++i){
			t *= b;
			t %= m;
		}
		printf("%d\n", (int)t);
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 0

static void solve(void){
	int s, d, a, b, n;

	for(scanf("%d", &n); n>0; --n){
		scanf("%d%d", &s, &d);
		b = (s-d)/2; a = s-b;
		if(b<0 || (a-b!=d)){
			puts("impossible");
		}else{
			printf("%d %d\n", a, b);
		}
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

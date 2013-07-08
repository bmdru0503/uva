#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 32

static void solve(void){
	char num[M];
	int n, a, cs;
	for(scanf("%d\n", &cs); cs>0; --cs){
		gets(num);
		n = strtol(num, NULL, 10);
		for(a=0; n; n>>=1) a += n&1;
		printf("%d ", a);
		n = strtol(num, NULL, 16);
		for(a=0; n; n>>=1) a += n&1;
		printf("%d\n", a);
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

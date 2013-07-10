#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 0

static void solve(void){
	int n, c;
	long long t;
	while(~scanf("%d", &n)){
		for(t=1, c=1; t%n; ++c){
			/**
			 * t = t*10+1
			 * (a*b+1)%n = ((a%n)*(b%n)+1)%n
			 * ø…“‘”√ (a%n)*(b%n)+1ÃÊªª a*b+1
			 * (111%8)=((11%8)*(10%8)+1)%8
			 */
			t = (t%n)*(10%n) + 1;
		}
		printf("%d\n", c);
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

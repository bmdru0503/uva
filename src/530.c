#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 1
#define M 0

int gcd(int a, int b){
	int c;
	if(b>a){
		c=a; a=b; b=c;
	}
	while(b){
		c= a%b;
		a = b;
		b= c;
	}
	return a;
}

static void solve(void){
	int m, n, i, ans;
	int c, d;
	while(scanf("%d%d", &m, &n), m){
		if(2*n>m) n = m - n;
		for(ans=1, d=m, i=1; i<=n; ++i, --d){
			c = gcd(d, i);
			ans /= (i/c);
			ans *= (d/c);
		}
		printf("%d\n", ans);
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

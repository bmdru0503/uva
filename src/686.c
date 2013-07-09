#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M ((1<<15)+1)

static int prime[M];

void seize(void){
	int i,j;
	memset(prime, -1, sizeof(prime));
	for(i=4; i<M; i+=2) prime[i]=0;
	for(i=3; i<M; i+=2){
		if(prime[i]){
			for(j=i*i; j<M; j+=i){
				prime[j] = 0;
			}
		}
	}
}
static void solve(void){
	int n, i, ans;
	seize();
	while(scanf("%d", &n), n){
		for(ans=0, i=2; i<=n/2; ++i){
			if(prime[i] && prime[n-i]) ++ans;
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

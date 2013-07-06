#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 1000001
static int prime[M];
static void solve(void){

	int i, j, n;
	memset(prime, -1, sizeof(prime));
	for(i=2; i<M; ++i){
		if(prime[i]){
			for(j=i*2; j<M; j +=i) prime[j] = 0;
		}
	}
	while(scanf("%d", &n), n){
		if(prime[n-2]){i=2;}
		else{
			for(i=3; i<=n/2; i+=2){
				if(prime[i] && prime[n-i]) break;
			}
		}
		if(i>n/2){
			printf("Goldbach's conjecture is wrong.\n");
		}else{
			printf("%d = %d + %d\n", n, i, n-i);
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

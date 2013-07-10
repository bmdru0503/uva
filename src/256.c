#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 1
#define M 100000
static int radix[] = {10, 100, 1000, 10000};
static int start[4];
static int elem[M];
static void solve(void){
	int i, s, t, u;
	int n;
	for(u=0, i=0; i<4; ++i){
		start[i] = u;
		for(s=0; s<radix[i]; ++s){
			for(t=0; t<radix[i]; ++t){
				if((s+t)*(s+t)==(s*radix[i]+t)){
					elem[u++] = s*radix[i]+t;
				}
			}
		}
	}
	start[i] = u;
	while(~scanf("%d", &n)){
		for(n=n/2-1, i=start[n]; i<start[n+1]; ++i){
			if(n==0) {
				printf("%02d\n", elem[i]);
			}else if(n==1){
				printf("%04d\n", elem[i]);
			}else if(n==2){
				printf("%06d\n", elem[i]);
			}else if(n==3){
				printf("%08d\n", elem[i]);
			}

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

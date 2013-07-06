#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 101

static void solve(void){
	int primes[M];
	int temp[M], i, j, k, mk;
	int n;

	memset(temp, -1, sizeof(temp));
	for(k=0,i=2; i<M; ++i){
		if(!temp[i]) continue;
		primes[k++] = i;
		for(j=i*i; j<M; j +=i){
			temp[j] = 0;
		}
	}
	while(scanf("%d", &n), n){
		memset(temp, 0, sizeof(temp));
		mk = 0; /* 出现的最大质数 序号*/
		for(i=2; i<=n; ++i){
			for(j=i, k=0; j>1; ++k){
				while(j%primes[k]==0){
					j /=primes[k];
					++temp[k];
					mk = k>mk?k:mk;
				}
			}
		}
		printf("%3d! =", n);

		for(i=0; i<=mk; ++i){
			if(i&& (i%15==0)){
				printf("\n      "); /* six space  %3d!-  */
			}
			printf("%3d", temp[i]);
		}
		printf("\n");
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

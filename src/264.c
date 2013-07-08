#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 20001
static int seq[M];
static void solve(void){
	int i, j,k, n;
	seq[1] = 1;
	for(i=2; i<M; ++i){
		if(i%2){
			seq[i] = seq[i-1] + 2*(i-1);
		}else{
			seq[i] = seq[i-1] + 1;
		}
	}
	while(~scanf("%d", &n)){
		for(i=1; seq[i]<n; ++i);
		if(seq[i]-i>=n){
			for(--i, j=i+1, k=seq[i]; k!=n; ++k, --i);
		}else{
			for(j=i+1, k=seq[i]; k!=n; --k, --i);
		}
		printf("TERM %d IS %d/%d\n", n, j-i, i);
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

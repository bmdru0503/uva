#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 10001

static void solve(void){
	int arr[M];
	int k, i, x;
	k=0;
	while(~scanf("%d", &x)){
		for(i=k-1; i>=0 && arr[i]>x; --i){
			arr[i+1] = arr[i];
		}
		arr[i+1] = x;
		++k;
		printf("%d\n", k%2?arr[k/2]:(arr[k/2]+arr[k/2-1])/2);
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

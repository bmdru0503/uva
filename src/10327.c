#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 1
#define M 1001

static void solve(void){
	int data[M];
	int n, ans, i, j, t;
	while(~scanf("%d", &n)){
		for(i=0; i<n; ++i){
			scanf("%d", data+i);
		}
		for(ans=0, i=n-1; i>0; --i){
			for(j=0; j<i; ++j){
				if(data[j]>data[j+1]){
					t = data[j]; data[j]=data[j+1]; data[j+1]=t;
					++ans;
				}
			}
		}
		printf("Minimum exchange operations : %d\n", ans);
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

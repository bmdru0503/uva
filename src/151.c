#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 102

static void solve(void){
	int arr[M];
	int n, k ,last, i, p, q;
	while(scanf("%d", &n), n){
		k=1;
		while(1){
			memset(arr, 0, sizeof(arr));
			arr[0] = 1;
			q=n-1; p =0;
			while(q){
				for(i=0; i<k-1; ++i){  /* 移动 K-1次 */
					while(arr[p])  p = (p+1)%(n);
					p = (p+1)%n;
				}
				while(arr[p])  p = (p+1)%(n);  /* 再移一次  */
				arr[p] = 1; /* 出圈 */
				--q;
			}
			if(p==12) break;
			++k;
		}
		printf("%d\n", k);
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

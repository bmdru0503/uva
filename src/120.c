#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 31
static int pan[M];
static int tmp[M];
static char line[256];
static int cmp(const void *a, const void *b){
	return *((int *)a) - *((int*)b);
}
static void swap(int *a, int *b){
	int c;
	c=*a; *a=*b; *b=c;
}
static void solve(void){
	char *pch;
	int i, j, k, u ,v;
	while(gets(line)){
		for(pch=line, i=0; *pch; ++i){
			tmp[i]=pan[i] = strtol(pch, &pch, 10);
		}
		puts(line);
		qsort(tmp, i, sizeof(tmp[0]), cmp);
		for(j=i-1; j>0; --j){
			for(k=j; k>=0 && pan[k]<tmp[j]; --k);
			if(k==j) continue;  /* in right place  */
			if(k!=0){
				/* flip between k and 0 */
				printf("%d ", i-k);
				for(u=0, v=k; u<v; ++u, --v) swap(pan+u, pan+v);
			}
			/* flip between 0 and j */
			printf("%d ", i-j);
			for(u=0, v=j; u<v; ++u, --v) swap(pan+u, pan+v);
		}
		puts("0");
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 100000 /* 注意此处M的值要取大些 */

static void solve(void){
	char src[M], dest[M];
	char *p, *q;
	while(scanf("%s%s", src, dest)!=EOF){
		p = src; q=dest;
		while(*p){
			if(!*q || (!(q=strchr(q, *p)))) break;
			++q; ++p;
		}
		puts(*p?"No":"Yes");
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


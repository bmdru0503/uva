#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 101
static char para[M][M];
static void solve(void){
	int i, j, k, max_len;
	memset(para, 0, sizeof(para));
	for(max_len=0,k=0; gets(para[k]); ++k){
		max_len = (max_len>strlen(para[k])) ? max_len : strlen(para[k]);
	}
	for(j=0; j<max_len; ++j){
		for(i=k-1; i>=0; --i){
			putchar(para[i][j] ? para[i][j]: ' ');
		}
		putchar('\n');
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

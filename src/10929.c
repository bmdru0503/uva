#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 1024
static char num[M];
static void solve(void){
	int n, i;
	while(gets(num)){
		if(strcmp(num, "0")==0) break;
		for(n=0, i=0; num[i]; ++i){
			n = n*10 + num[i]-'0';
			n %= 11;
		}
		printf("%s is%s a multiple of 11.\n", num, n?" not":"");
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

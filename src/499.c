#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 128
/* A=65, a=97, ²»Á¬Ðø */
static void solve(void){
	int frq[M];
	char line[2048];
	int mf, i;
	int ch;
	memset(frq, 0, sizeof(frq));
	mf = 0;
	while(gets(line)){
		for(i=0; i<M; ++i){
			if(isalpha(i)){
				frq[i] = 0;
			}else{
				frq[i] = -1;
			}
		}
		for(mf=0, i=0; i<strlen(line); ++i){
			if(isalpha(line[i])){
				++frq[line[i]];
				mf = frq[line[i]]>mf ? frq[line[i]]:mf;
			}
		}
		for(i=0; i<M; ++i){
			if(frq[i]==mf){
				putchar(i);
			}
		}
		printf(" %d\n", mf);
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

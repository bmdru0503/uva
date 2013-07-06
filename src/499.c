#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 1
#define M 64
/* A=65, a=97, ²»Á¬Ðø */
static void solve(void){
	int frq[M];
	int mf, i;
	int ch;
	memset(frq, 0, sizeof(frq));
	mf = 0;
	while((ch=getchar())){
		if(ch == '\n' || ch==EOF){
			for(i=0; i<M; ++i){
				if(frq[i] == mf){
					putchar('A'+i);
				}
			}
			printf(" %d\n", mf);
			if(ch==EOF) break;
			memset(frq, 0, sizeof(frq));
			mf = 0;
		}else{
			if(isalpha(ch)){
				++frq[ch-'A'];
				if(mf < frq[ch-'A']) mf = frq[ch-'A'];
			}
		}
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

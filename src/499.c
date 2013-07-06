#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 1
#define M 52
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
					if(i>=26){
						putchar('a'+i-26);
					}else{
						putchar('A'+i);
					}
				}
			}
			printf(" %d\n", mf);
			if(ch==EOF) break;
			memset(frq, 0, sizeof(frq));
			mf = 0;
		}else{
			i = -1;
			if(isupper(ch)){
				i = ch - 'A';
			}
			if(islower(ch)){
				i = ch - 'a' + 26;
			}
			if(i!=-1){
				++frq[i];
				mf = frq[i]>mf?frq[i]:mf;
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

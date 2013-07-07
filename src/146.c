#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 128

static void solve(void){
	char line[M], tmp;
	int i, j, nlen;
	while(gets(line)){
		if(line[0]=='#') break;
		nlen = strlen(line);
		/* find ascendant sequence from end */
		for(i=nlen-1; i>0; --i){
			if(line[i-1]<line[i]) break;
		}
		if(i>0){
			/* find first larger from end */
			for(j=nlen-1; j>=i && line[j]<=line[i-1]; --j);
			tmp = line[i-1]; line[i-1]=line[j]; line[j] = tmp;
			/* change from desc to asce */
			for(j=nlen-1; j>i; --j, ++i){
				tmp = line[i]; line[i]=line[j]; line[j] = tmp;
			}
			puts(line);
		}else{
			puts("No Successor");
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

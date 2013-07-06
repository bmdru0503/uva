#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 1024

static void solve(void){
	char line[M], ch;
	int repeat, i, j;
	repeat=0;
	while(gets(line)){
		if(line[0]=='\0'){
			printf("\n");
		}else{
			for(i=0; i<strlen(line); ++i){
				if(line[i]=='!') putchar('\n');
				else if(isdigit(line[i])){
					repeat += line[i]-'0';

				}else{
					ch = line[i];
					if(ch=='b') ch=' ';
					for(j=0; j<repeat; ++j){
						putchar(ch);
					}
					repeat = 0;
				}
			}
			putchar('\n');
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

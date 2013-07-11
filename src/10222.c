#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 0

static char *kbds = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
static void solve(void){
	int ch;
	char *p;
	while((ch=getchar())!=EOF){
		 p = strchr(kbds, tolower(ch));
		 putchar(p?(*(p-2)):ch);
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

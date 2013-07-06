#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 0

static void solve(void){
	int b, p, m, i;
	long long t, s;
	while(~scanf("%d%d%d", &b, &p, &m)){
		t=1; /* 最终结果 */
		s=b;
		while(p>=1){
			if(p%2) t = t*s%m;
			s = s*s%m;  /* s为 b^(2^i) %m的值  */
			p /= 2;
		}
		printf("%d\n", (int)t);
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

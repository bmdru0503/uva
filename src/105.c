#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 10002

static int skyline[M]; /* skyline[i]表示 [i..i+1]的段的高度 */
static void solve(void){
	int l, h, r, minl, maxr;
	int i, j;
	memset(skyline, 0, sizeof(skyline));
	minl = M; maxr=-1;
	while(~scanf("%d%d%d", &l, &h, &r)){

		minl = minl > l ? l : minl;
		maxr = maxr < r ? r: maxr;
		for(i=l; i<r; ++i){
			skyline[i] = skyline[i]>h ? skyline[i] : h;
		}
	}
	for(j=-1, i=minl; i<maxr; ++i){
		if(skyline[i]!=j){
			printf("%d %d ", i, skyline[i]);
			j = skyline[i];
		}
	}
	printf("%d 0\n", maxr);

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

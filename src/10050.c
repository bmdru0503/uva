#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 3651

static void solve(void){
	int days[M];
	int cs, nd, np, i, j, ip;
	int ans;
	for(scanf("%d", &cs); cs>0; --cs){
		scanf("%d%d", &nd, &np);
		for(i=0; i<=nd; ++i) days[i] = 0;
		for(i=0; i<np; ++i){
			scanf("%d", &ip);
			for(j=0; j<=nd; j +=ip){
				days[j]=1;
			}
		}
		for(ans=0,i=1; i<=nd; ++i){
			if(days[i] && (i%7!=6) && (i%7!=0)) ++ans;
		}
		printf("%d\n", ans);
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

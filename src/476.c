#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 1
#define M 12

static double rect[M][4];

static void solve(void){
	int i,j, n, flag;
	double x, y;
	char ch;
	for(n=0; scanf("%c", &ch), ch!='*'; ++n){
		scanf("%lf%lf%lf%lf\n", &rect[n][0],&rect[n][1],&rect[n][2],&rect[n][3]);
	}
	for(j=1; scanf("%lf%lf", &x, &y); ++j){
		if(x==9999.9 && y==9999.9) break;
		for(flag=1, i=0; i<n; ++i){
			if(x>rect[i][0] && x<rect[i][2] && y<rect[i][1] && y>rect[i][3]){
				printf("Point %d is contained in figure %d\n", j, i+1);
				flag = 0;
			}
		}
		if(flag){
			printf("Point %d is not contained in any figure\n", j);
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

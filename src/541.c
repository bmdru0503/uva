#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 101
static int mx[M][M];
static void solve(void){
	int n, i, j;
	int sc, sr, oddr, oddc, r, c;
	while(scanf("%d", &n), n){
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				scanf("%d", &mx[i][j]);
			}
		}
		oddr = oddc = 0;
		for(i=0; i<n; ++i){
			sc = sr = 0;
			for(j=0; j<n; ++j){
				sr += mx[i][j];
				sc += mx[j][i];
			}
			if(sr%2){
				++oddr; r=i;
			}
			if(sc%2){
				++oddc; c=i;
			}
		}
		if(oddr==0 && oddc==0){
			puts("OK");
		}else if(oddr==1 && oddc==1){
			printf("Change bit (%d,%d)\n", r+1, c+1);
		}else{
			puts("Corrupt");
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

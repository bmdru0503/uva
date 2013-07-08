#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 5001
static char fib[M][M];
static void solve(void){
	int i, j, n, cr;
	fib[0][0]=0;
	fib[1][0]=fib[2][0]=1;
	fib[0][1]=fib[1][1]=fib[2][1]=-1;
	for(i=3; i<M; ++i){
		for(cr=0, j=0; fib[i-2][j]!=-1; ++j){
			cr += fib[i-1][j] + fib[i-2][j];
			fib[i][j] = cr %10;
			cr /= 10;
		}
		if(fib[i-1][j]!=-1){
			cr += fib[i-1][j];
			fib[i][j++] = cr%10;
			cr /=10;
		}
		if(cr)fib[i][j++] = cr;
		fib[i][j] = -1;
	}
	while(~scanf("%d", &n)){
		printf("The Fibonacci number for %d is ", n);
		for(i=0; fib[n][i]!=-1; ++i);
		for(--i; i>=0; --i)printf("%d", fib[n][i]);
		putchar('\n');

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

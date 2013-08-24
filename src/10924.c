#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 2000
static int prime[M];
static void solve(void){
	int i, j;
	char word[32];
	memset(prime, -1, sizeof(prime));
	for(i=2; i<M; ++i){
		if(prime[i]){
			for(j=i*i; j<M; j+=i) prime[j] = 0;
		}
	}
	while(gets(word)){
		for(j=i=0; word[i]; ++i){
			j += (isupper(word[i])) ? (word[i]-'A'+27):(word[i]-'a'+1);
		}
		if(prime[j]){
			printf("It is a prime word.\n");
		}else{
			printf("It is not a prime word.\n");
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

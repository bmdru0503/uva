#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 0

char lcd[5][32]={	"b-bbbbb-bb-bbbbb-bb-bb-bb-bb-b",
					"|b|bb|bb|bb||b||bb|bbbb||b||b|",
					"bbbbbbb-bb-bb-bb-bb-bbbbb-bb-b",
					"|b|bb||bbbb|bb|bb||b|bb||b|bb|",
					"b-bbbbb-bb-bbbbb-bb-bbbbb-bb-b"
				};
static void solve(void){
	char digit[32], ch;
	int n, i, j , k, x, s, t, u, v;
	int flag = 0;
	while(scanf("%d%s", &n, digit), n){
		flag = 1;
		for(i=0; i<5; ++i){
			v = i%2 ? n : 1;
			for(u=0; u<v; ++u){
				for(j=0; digit[j]; ++j){
					x = digit[j]-'0';
					for(k=0; k<3; ++k){
						ch = lcd[i][x*3+k];
						t = k%2?n:1;
						for(s=0; s<t; ++s){
							putchar(ch=='b'?' ':ch);
						}
					}
					if(digit[j+1])putchar(' ');
				}
				putchar('\n');
			}
		}
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

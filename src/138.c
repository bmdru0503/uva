#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define OJ_TEST 0
#define LOCAL_TEST 0
#define M 0

static void solve(void){
	/*
	 * 此法铁定超时， 还有，如何ls, rs用int, 算的结果不正确。
	int me, cnt, end;
	long long ls, rs;
	for(cnt=0, me=ls=0; cnt<10; ){
		for(ls+=me, ++me, rs=end=me+1; rs<ls; ++end, rs +=end);
		if(rs == ls){
			printf("%10d%10d\n", me, end);
			++cnt;
		}
	}
	*/
	/*
	 * 也超时，  得到  2*me*me = end*end+end
	long long me, end, sa ;
	int cnt;
	for(me=1, end=1, cnt=0; cnt<10; ){
		for(me +=1, end=me+1, sa=me*me*2; sa>end*end+end; ++end);
		if(sa == end*end+end){
			++cnt;
			printf("%10d%10d\n", (int)me, (int)end);
		}
	}

	*/
	/*
	 * 二分查找，速度提升了
	long long me, end, sa ;
	long long low ,high, mid;
	int cnt;
	for(me=1, end=1, cnt=0; cnt<10; ){
		++me;
		low = me+1; high = 2*me;
		sa = me*me*2;
		while(low <= high){
			mid = low + (high-low)/2;
			if(sa == mid*mid+mid){
				++cnt;
				printf("%10d%10d\n", (int)me, (int)mid);
				break;
			}else if(sa>mid*mid+mid){
				low = mid+1;
			}else{
				high = mid-1;
			}
		}
	}
	*/
	/*
	 * 佩尔方程
	 * x^2-n*y^2=1 解为：
	 * x(i+1) = x1*xi+n*y1*yi
	 * y(i+1) = x1*yi + xi*y1
	 *
	 * x^2+x - 2y^2=0
	 * (2x+1)^2-8y^2=1
	 * x^2 - 8y^2 = 1
	 * 第一个解为 x1=3, y1=1
	 *
	 */
	int x1=3, y1=1;
	int xi=3, yi=1;
	int m, n, i;
	for(i=0; i<10; ++i){
		m = x1*xi + 8*y1*yi;
		n = x1*yi + xi*y1;
		printf("%10d%10d\n", n, (m-1)>>1);
		xi=m; yi=n;
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

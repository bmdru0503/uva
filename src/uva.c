#include <stdio.h>
#include <stdlib.h>

void run(void);
int main(void) {
	freopen("data.dat", "r", stdin);
	run();
	return EXIT_SUCCESS;
}

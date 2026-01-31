#include <stdio.h>
#define SPACING 4
#define ceil(a) ((a) == (int)(a) ? (int)(a) : (int)(a) + 1)
static inline int matoi(char *);
static void cbin(int);
int main(int argc, char **args) {
	if (argc < 2) goto L;
	for (int i = 1; i < argc; i++) {
		cbin(matoi(args[i]));	
		putchar('\n');	
	}
L:
	return 0;
}
static inline int matoi(char *s) {
	register int c = 0;
    register signed char sg = 1;
    if (*s == '-') {
        s++;
        sg = -1;
    }
	while (*s && (c = 10 * c + (*s++ - '0')));
	return c * sg;
}
static void cbin(int n) {
	if (n == 0) {
		printf("0000");
		return;
	}
	register int i = 31;
	while (!(n >> i-- & 1));
	i++;
	i = SPACING * ceil((i + 1) / (float)SPACING) - 1;
	register int d = 0;
	for (; i >= 0; i--) {
		printf("%d", n >> i & 1);
		d++;
		if (d == 4) {
			putchar(' ');
			d = 0;
		}
	}			
}


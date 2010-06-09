#include <stdio.h>
#include <malloc.h>
#include <assert.h>
void swap(char *c1, char *c2) {
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}
void reverse(char *str, int max) {
	int i;
	for (i = 0; i <= max/2; i++) {
		swap(&str[i], &str[max - i]);
	}
}
char *alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
/*
 * decimal to base, up to a base of strlen(alpha)
 */
char *dec2base(float dec, int base) {
	assert (base <= 36);

	int mant = dec;
	float deci = dec - mant;
	char *bStr = (char*) malloc(sizeof(char)*50);
	int i = 0;
	while (mant > 0) {
		bStr[i++] = alpha[mant % base];
		mant /= base;
	}
	reverse(bStr, i - 1);

	if(deci > 0) bStr[i++] = '.';

	while (deci > 0) {
		deci *= base;
		bStr[i++] = alpha[(int)deci];
		deci -= (int)deci;
	}
	bStr[i] = '\0';
	return bStr;
}
int main(void) {
	float num;
	int base;
	scanf("%f %d", &num, &base);
	char *bin = dec2base(num, base);
	printf("%s\n", bin);
	free(bin);
	return 0;
}

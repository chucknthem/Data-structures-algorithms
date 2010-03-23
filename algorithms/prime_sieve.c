#include <stdio.h>
#include <malloc.h>

int nextPrime(int i, char *sieve, int max) {
	while(i < max && !sieve[i]) {
		i++;
	}
	return i;
}
void setNotPrime(int i, char *sieve, int max) {
	int j;
	for(j = i; j < max; j += i) {
		sieve[j] = 0;
	}
}

int main(int argc, char**argv) {
	int n = atoi(argv[1]);
	char *sieve = (char*) malloc(sizeof(char));
	int i;
	for(i = 0; i < n; i++) {
		sieve[i] = 1;
	}

	for(i = 2; i < n; i = nextPrime(i, sieve, n)) {
		printf("%d ", i);
		setNotPrime(i, sieve, n);
	}

	return 0;
}

#include <stdio.h>

int fastExp(int b, int e, int m)
{
	int result = 1;
	if (1 & e)
		result = b;
	while (1) {
		if (!e) break;
		e >>= 1;
		b = (b * b) % m;
		if (e & 1)
			result = (result * b) % m;
	}
	return result;
}

int main()
{
	printf("Compute b to the power e modulo m");
	int b = 0, e = 0, m = 0;
	printf("Enter b:");
    scanf("%d", &b);
	printf("Enter e:");
    scanf("%d", &b);
	printf("Enter m:");
    scanf("%d", &m);
	printf("%d to the power %d ≡ %d (mod%d)\n", b, e, fastExp(b, e, m), m);
	return 0;
}
#include <stdio.h>
void recursive(int n)
{
	printf("%d\n", n);
	if (n == 0)
		return ;
	else
		recursive(n - 1);
}

int tail_recursive(int n)
{
	printf("%d\n", n);
	if (n == 0)
		return (0);
	else
		return tail_recursive(n - 1);
}

int main(void)
{
	tail_recursive(10000000);
	return (0);
}

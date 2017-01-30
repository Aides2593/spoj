#include <stdio.h>
#include <math.h>

#define MAXN 10001
int n, ans;

int mem[MAXN] = {0,};
void Slove(int index)
{
	int counter = 0;
	if (mem[index])
	{
		ans += mem[index];
		return;
	}
	int l = (int)sqrt((double)index);
	for (int i = 1; i <= l; i++)
		if (index % i == 0)
			counter ++;
	ans += counter;
	mem[index] = ans;// + counter;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <=n; i++)
		Slove(i);
	printf("%d", ans);
	return 0;
}
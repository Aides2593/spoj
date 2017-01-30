#include <stdio.h>

#define MAXRC 1001
int row, col, checkr, checkc, ans;
bool visit[MAXRC][MAXRC];
char p[MAXRC][MAXRC];
int t[4][2] ={{0, 1},{0, -1},{1, 0},{-1, 0}};
void DFS(int r, int c, int len)
{
	if (r >= row)
	{
		return;
	}
	else
		if (c >= col)
			DFS(r + 1, 0, len);
	if (ans < len)
	{
		ans = len;
		checkr = r;
		checkc = c;
	}
	int flag = false;
	for (int i = 0; i < 4; i++)
	{
		int tmpr = r + t[i][0];
		int tmpc = c + t[i][1];
		if (tmpr > -1 && tmpr < row && tmpc > -1 && tmpc< col &&p[tmpr][tmpc] != '#' && !visit[tmpr][tmpc])
		{
			visit[tmpr][tmpc] = true;
			p[tmpr][tmpc] = '#';
			DFS(tmpr, tmpc, len + 1);
			visit[tmpr][tmpc] = false;
			p[tmpr][tmpc] = '.';
			flag = true;
		}
	}
}
int main()
{
	int testcase;
	//freopen("../LABYR1.txt", "r", stdin);
	scanf("%d", &testcase);
	while (testcase --)
	{
		scanf("%d %d", &col, &row);
		for (int i = 0; i < row; i++)
			scanf("%s", p[i]);

		for (int i = 0; i< row; i++)
			for (int j = 0; j < col; j++)
				visit[i][j] = 0;

		
		ans = 0;
		int i, j;
		bool flag = false;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (p[i][j] != '#')
				{
					flag = true;
					break;
				}

			}
			if (flag)
				break;
		}
			checkr = -1;
			checkc = -1;
			visit[i][j] = true;
			DFS(i, j, 0);
			visit[i][j] = false;
			if (checkr != -1 && checkc != -1)
				DFS(checkr, checkc, 0);
		printf("Maximum rope length is %d.\n", ans);
	}
	return 0;
}

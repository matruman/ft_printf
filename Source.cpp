#include <iostream>
#include <stdlib.h>
using namespace std;

bool optioncheck(int **a, int r)
{
	int m = 0;
	int k = 0;
	int g = r - 1;
	bool f;
	f = true;
	while (g > 0)
	{
		m = 0;
		k = 0;
		while (a[g][k] == a[r][k])
		{
			if (a[g][k] == a[r][k])
				m++;
			k++;
		}
		if (a[r][k] == 0)
			f = false;
		if (!f)
			break;
		g--;
	}
	return f;
}

void print(int **a, int r)
{
	for (int i = 0; i < r; i++)
	{
		cout << i + 1 << "\t";
		for (int j = 0; a[i][j] > 0; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}

int main(int ac, char **av)
{
	int d = 400000;
	int w = 15;
	bool f;
	int **c = new int*[d];
	for (int i = 0; i < d; i++)
	{
		c[i] = new int[w];
	}
	int n = 0;
	n = atoi(av[1]);
	int x = 1;
	int y = 0;
	int s = 0;
	int m = 0;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < w; j++)
			c[i][j] = 0;
	c[0][0] = n;
	while (c[y][0] > 0)
	{
		int i = 0;
		int j = 0;
		while (c[y][i] > 2)
		{
			j = 0;
			while (c[y][i + j] > 1)
			{
				if (i + j + 1 > w - 1)
					break;
				if (((c[y][i] - c[y][i + 1]) < 3 && (j == 0))
						|| (c[y][i] - c[y][i + 1]) < 2
						|| (c[y][i + j] - c[y][i + j + 1]) < 2)
				{
					j++;
					continue;
				}
				for (int k = 0; k < w; k++)
					c[x][k] = c[y][k];
				c[x][i + j + 1]++;
				c[x][i]--;
				m++;
				if (optioncheck(c, x))
					x++;
				j++;
			}
			i++;
			if (i > w - 1)
				break;
		}
		y++;
	}
//	print(c, x);
	cout << "Amount of different options: " << x << "\n";
	cout << "Amount of all options: " << m << "\n";
	return 0;
}

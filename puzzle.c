/*
Objective:
Create a 10-digit number comprised of 0-9 (no repeats)
such that a number comprised of the first n digits is divisible by n.

For example, for the number 123,
1 is divisible by 1.
12 is divisible by 2.
123 is divisible by 3.

Turns out: the solution is
3 8 1 6 5 4 7 2 9 0

3				/1 == 	3
38				/2 == 	19
381				/3 == 	127
3,816			/4 == 	954
38,165			/5 == 	7,633
381,654			/6 == 	63,609
3,816,547		/7 == 	545,221
38,165,472		/8 == 	4,770,684
381,654,729		/9 == 	42,406,081
3,816,547,290	/10 == 	381,654,729
*/

#include <stdio.h>
#include <stdbool.h>

bool repeatsFound(int,int,int,int,int,int,int,int,int,int);
void test(int,int,int,int,int,int,int,int,int,int);

int main() 
{
	int i,j,k,l,m,n,p,q,r,s; // skipping 'o' because it looks too much like zero (so why didn't you skip 'l'? It looks like 1.)

	// printf("Hello, World! \n");
	// test(1,2,3,4,5,6,7,8,9,0);
	// test(1,2,2,4,5,6,7,8,9,0);

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			for (k = 0; k < 10; k++)
			{
				for (l = 0; l < 10; l++)
				{
					m=5;
					/*
					for (m = 0; m < 10; m++)
					{
						*/
						for (n = 0; n < 10; n++)
						{
							for (p = 0; p < 10; p++)
							{
								for (q = 0; q < 10; q++)
								{
									for (r = 0; r < 10; r++)
									{
										/*
										for (s = 0; s < 10; s++)
										{
											test(i,j,k,l,m,n,p,q,r,s);
										}
										*/
										s=0;
										test(i,j,k,l,m,n,p,q,r,s);
									}
								}
							}
						}
					/*
					}
					*/
				}
			}
		}
	}
   
	return 0;
}

bool repeatsFound(int i,int j,int k,int l,int m,int n,int p,int q,int r,int s)
{
	if (i!=j && i!=k && i!=l && i!=m && i!=n && i!=p && i!=q && i!=r && i!=s)
	{
		if (j!=k && j!=l && j!=m && j!=n && j!=p && j!=q && j!=r && j!=s)
		{
			if (k!=l && k!=m && k!=n && k!=p && k!=q && k!=r && k!=s)
			{
				if (l!=m && l!=n && l!=p && l!=q && l!=r && l!=s)
				{
					if (m!=n && m!=p && m!=q && m!=r && m!=s)
					{
						if (n!=p && n!=q && n!=r && n!=s)
						{
							if (p!=q && p!=r && p!=s)
							{
								if (q!=r && q!=s)
								{
									if (r!=s)
									{
										// no repeats found
										return false;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return true;
}

void test(int i,int j,int k,int l,int m,int n,int p,int q,int r,int s)
{
	// Ensure there are no repeated digits
	if (repeatsFound(i,j,k,l,m,n,p,q,r,s))
	{
		return;
	}
	
	// Now test the numbers comprised of the first n digits
	if (i%1 != 0)
	{
		return; // no way this will fail, this is trivial
	}

	if ((i*10 + j)%2 != 0)
	{
		return;
	}

	if ((i*100 + j*10 + k)%3 != 0)
	{
		return;
	}

	if ((i*1000 + j*100 + k*10 + l)%4 != 0)
	{
		return;
	}

	// this one might as well be: if (m != 5)
	/*
	if ((i*10000 + j*1000 + k*100 + l*10 + m)%5 != 0) 
	{
		return;
	}
	*/

	if ((i*100000 + j*10000 + k*1000 + l*100 + m*10 + n)%6 != 0)
	{
		return;
	}

	if ((i*1000000 + j*100000 + k*10000 + l*1000 + m*100 + n*10 + p)%7 != 0)
	{
		return;
	}

	if ((i*10000000 + j*1000000 + k*100000 + l*10000 + m*1000 + n*100 + p*10 + q)%8 != 0)
	{
		return;
	}

	if ((i*100000000 + j*10000000 + k*1000000 + l*100000 + m*10000 + n*1000 + p*100 + q*10 + r)%9 != 0)
	{
		return;
	}

	// this one might as well be: if (s != 0)
	/*
	if ((i*1000000000 + j*100000000 + k*10000000 + l*1000000 + m*100000 + n*10000 + p*1000 + q*100 + r*10 + s)%10 != 0)
	{
		return;
	}
	*/

	// If we made it all the way down here, this must be a solution. Print it.
	printf("Solution: %d %d %d %d %d %d %d %d %d %d\n",i,j,k,l,m,n,p,q,r,s);
}

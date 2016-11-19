/*
Objective:
Create a 10-digit number comprised of 0-9 (no repeats)
such that a number comprised of the first n digits is divisible by n.

For example, for the number 123,
1 is divisible by 1.
12 is divisible by 2.
123 is divisible by 3.
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
					for (m = 0; m < 10; m++)
					{
						for (n = 0; n < 10; n++)
						{
							for (p = 0; p < 10; p++)
							{
								for (q = 0; q < 10; q++)
								{
									for (r = 0; r < 10; r++)
									{
										for (s = 0; s < 10; s++)
										{
											// test(i,j,k,l,m,n,p,q,r,s);
										}
									}
								}
							}
						}
					}
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

	// If we made it all the way down here, this must be a solution. Print it.
	printf("Solution: %d %d %d %d %d %d %d %d %d %d\n",i,j,k,l,m,n,p,q,r,s);
}

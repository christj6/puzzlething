
// javac PuzzleThing.java
// java -cp . PuzzleThing

// this puzzle thing here: http://mscroggs.co.uk/puzzles/VL

/*
	after running this program, the solution seems to be:

	1 5	2
	7	4	9
	6	8 3
*/

public class PuzzleThing
{
	public static void main(String[] args)
	{
		int[] values = new int[9];
		int iIndex = 0;

		// 9! possibilities, so 362,880 possibilities to consider.
		int a,b,c,d,e,f,g,h,i;

		for (a=1;a<=9;++a)
		{
			for (b=1;b<=9;++b)
			{
				for (c=1;c<=9;++c)
				{
					for (d=1;d<=9;++d)
					{
						for (e=1;e<=9;++e)
						{
							for (f=1;f<=9;++f)
							{
								for (g=1;g<=9;++g)
								{
									for (h=1;h<=9;++h)
									{
										for (i=1;i<=9;++i)
										{
											//
											values[0]=a;
											values[1]=b;
											values[2]=c;
											values[3]=d;
											values[4]=e;
											values[5]=f;
											values[6]=g;
											values[7]=h;
											values[8]=i;

											if (uniqueValues(values))
											{
												// they're unique
												if (testSolution(values))
												{
													// valid solution
													for (iIndex=0;iIndex<values.length;++iIndex)
													{
														System.out.print(values[iIndex] + " ");
													}
													System.out.println("");
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
		}
	}

	public static boolean uniqueValues(int[] values)
	{
		// used in the series of nested for-loops to determine if all values are unique
		int i,j;

		for (i=0;i<values.length;++i)
		{
			for (j=i+1;j<values.length;++j)
			{
				if (values[i]==values[j])
				{
					return false;
				}
			}
		}

		return true;
	}

	public static boolean testSolution(int[] values)
	{
		// values represents a 3x3 grid where:
		/*
			x1 + x2 - x3 = 4
			x4 - x5 * x6 = 27
			x7 * x8 / x9 = 16
			and
			x1 + x4 - x7 = 2
			x2 - x5 * x8 = 8
			x3 * x6 / x9 = 6
		*/
		// x1-x9 are digits 1-9, where each digit is used exactly once.
		// values are read top-to-bottom and left-to-right,
		// ignoring the usual order of operations.
		// for example, 4+3*2 is 14, not 10.

		// horizontal equations
		if ((values[0] + values[1]) - values[2] != 4)
		{
			return false;
		}

		if ((values[3] - values[4]) * values[5] != 27)
		{
			return false;
		}

		if ((values[6] * values[7]) / values[8] != 16)
		{
			return false;
		}

		// vertical equations
		if ((values[0] + values[3]) - values[6] != 2)
		{
			return false;
		}

		if ((values[1] - values[4]) * values[7] != 8)
		{
			return false;
		}

		if ((values[2] * values[5]) / values[8] != 6)
		{
			return false;
		}

		return true;
	}
}

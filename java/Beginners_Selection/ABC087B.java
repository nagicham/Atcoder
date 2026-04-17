package Atcoder.Beginners_Selection;
import java.util.Scanner;

public class ABC087B
{
	public static void main(String[] args)
	{
		int a, b, c, x, count = 0;
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		x = sc.nextInt();
		for (int i = 0; i <= a; i++)
		{
			for (int j = 0; j <= b; j++)
			{
				for (int k = 0; k <= c; k++)
				{
					if (500 * i + 100 * j + 50 * k == x)
					{
						count++;
					}
				}
			}
		}
		System.out.println(count);
		sc.close();
	}
}

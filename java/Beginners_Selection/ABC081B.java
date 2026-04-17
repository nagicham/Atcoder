package Atcoder.Beginners_Selection;
import java.util.Scanner;

public class ABC081B
{
	public static void main(String[] args)
	{
		int n, count = 0;
		int[] a;
		boolean flag = true;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = sc.nextInt();
		}
		while (flag)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i] % 2 == 0)
				{
					a[i] /= 2;
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (flag) count++;
		}
		System.out.println(count);
		sc.close();
	}
}

package Atcoder.Beginners_Selection;
import java.util.Scanner;

public class ABC083B
{
	public static int func(int n)
	{
		int ans = 0;
		
		while (n > 0)
		{
			ans += n % 10;
			n /= 10;
		}
		
		return ans;
	}
	public static void main(String[] args)
	{
		int n, a, b, temp, sum = 0;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		a = sc.nextInt();
		b = sc.nextInt();
		for (int i = 1; i <= n; i++)
		{
			temp = func(i);
			if (a <= temp && temp <= b)
			{
				sum += i;
			}
		}
		System.out.println(sum);
		sc.close();
	}
}

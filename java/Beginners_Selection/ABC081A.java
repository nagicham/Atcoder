package Atcoder.Beginners_Selection;
import java.util.Scanner;

public class ABC081A
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		int count = 0;
		for (char c : str.toCharArray())
		{
			if (c == '1')
			{
				count++;
			}
		}
		System.out.println(count);
		sc.close();
	}
}

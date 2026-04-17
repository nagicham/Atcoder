package Atcoder.Daily_Training.day0410;
import java.util.Scanner;

public class A
{
    public static void main(String[] args)
    {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	String str = sc.next();

	if (str.lastIndexOf("tea") == n - 3)
	    {
		System.out.println("Yes");
	    }
	else
	    {
		System.out.println("No");
	    }
	sc.close();	
    }
}

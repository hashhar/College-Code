import java.util.Scanner;

public class Calculator {
	static int add(int a, int b) { return (a + b); }

	static int subtract(int a, int b) { return (a - b); }

	public static void main(String[] args) {
		int m = 0, result;

		Scanner sc = new Scanner(System.in);
		int choice = 0;
		while(choice <= 5)
		{
			System.out.println("1. Add\n2.Subtract\n3.Display M+\n4. Add M+\n5. Subtract M+\nAny other number to exit\n");
			choice = sc.nextInt();
			switch(choice) {
				case 1:
					System.out.println("Enter two numbers: ");
					result = add(sc.nextInt(), sc.nextInt());

					System.out.println("Result: " + result);
					System.out.println("Enter 1 to save in M+, 0 to continue");
					if (sc.nextInt() == 1)
						m = result;
					break;
				case 2:
					System.out.println("Enter two numbers: ");
					result = subtract(sc.nextInt(), sc.nextInt());
					System.out.println("Result: " + result);
					System.out.println("Enter 1 to save in M+, 0 to continue");
					if (sc.nextInt() == 1)
						m = result;
					break;
				case 3:
					System.out.println("M+: " + m);
					break;
				case 4:
					System.out.println("Enter a number: ");
					result = add(sc.nextInt(), m);
					System.out.println("Result: " + result);
					m = result;
					break;
				case 5:
					System.out.println("Enter a number: ");
					result = subtract(sc.nextInt(), m);
					System.out.println("Result: " + result);
					m = result;
					break;
			}
		}
	}
}

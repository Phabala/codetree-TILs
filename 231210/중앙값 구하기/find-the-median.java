import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int num1, num2, num3;

        if (a > b && a > c) {
            num1 = a;
            if (b < c) {
                num2 = c;
                num3 = b;
            } else {
                num2 = b;
                num3 = c;
            }
        } else if (b > a && b > c) {
            num1 = b;
            if (a < c) {
                num2 = c;
                num3 = a;
            } else {
                num2 = a;
                num3 = c;
            }
        } else {
            num1 = c;
            if (a < b) {
                num2 = b;
                num3 = a;
            } else {
                num2 = a;
                num3 = b;
            }
        }

        System.out.print(num2);
    }
}
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        for (int i = 1; i <= 5000; i++) {
            if ((n /= i) <= 1) {
                System.out.print(i);
                break;
            }
        }
    }
}
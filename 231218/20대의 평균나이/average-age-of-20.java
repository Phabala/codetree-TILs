import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int sum = 0;
        int count = 0;
        while(true) {
            int input = sc.nextInt();
            if (input >= 20 && input < 30) {
                sum += input;
                count++;
            } else {
                break;
            }
        }
        System.out.printf("%.2f", (double) sum / count);
    }
}
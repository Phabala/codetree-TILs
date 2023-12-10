import java.util.Scanner;

class Person {
        public int age;
        public char gender;
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Person p1 = new Person();
        Person p2 = new Person();

        p1.age = sc.nextInt();
        p1.gender = sc.next().charAt(0);

        p2.age = sc.nextInt();
        p2.gender = sc.next().charAt(0);

        if ((p1.age >= 19 && p1.gender == 'M') || (p2.gender >= 19 && p2.gender == 'M')) {
            System.out.print(1);
        } else {
            System.out.print(0);
        }
    }
}
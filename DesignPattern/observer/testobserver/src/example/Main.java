package example;

public class Main {
    public static void main(String[] args) {
        Clock c = new Clock("8");
        Doctor doctor = new Doctor(c);
        Developer developer = new Developer(c);
        Nerd nerd = new Nerd(c);

        //변화전
        {
            System.out.println(doctor.state);
            System.out.println(developer.state);
            System.out.println(nerd.state);
        }

        //시간 변화
        {
            c.setTime("9");
        }

        //변화후
        {
            System.out.println(doctor.state);
            System.out.println(developer.state);
            System.out.println(nerd.state);
        }
    }
}

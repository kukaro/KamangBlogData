package example;

public class Doctor implements Observer {
    public Clock clock;
    public String state = "보통";

    public Doctor(Clock clock) {
        this.clock = clock;
        this.clock.registerObserver(this);
    }

    @Override
    public void update() {
        //action!
        {
            if (clock.time.equals("9")) {
                state = "야근";
            }
        }
    }
}

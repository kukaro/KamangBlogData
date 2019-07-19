package example;

import java.util.ArrayList;

public class Clock implements Subject{
    public ArrayList<Observer> observerCollection;
    public String time;

    public Clock(String time) {
        observerCollection = new ArrayList<>();
        this.time = time;
    }

    @Override
    public void registerObserver(Observer observer) {
        observerCollection.add(observer);
    }

    @Override
    public void unregisterObserver(Observer observer) {
        observerCollection.remove(observer);
    }

    @Override
    public void notifyObservers() {
        for(Observer observer:observerCollection){
            observer.update();
        }
    }

    public void setTime(String time) {
        this.time = time;
        notifyObservers();
    }
}

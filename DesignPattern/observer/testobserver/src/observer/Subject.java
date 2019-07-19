package observer;

import java.util.ArrayList;

public interface Subject {
    ArrayList<Observer> observerCollection = null;
    void registerObserver(Observer observer);
    void unregisterObserver(Observer observer);
    default void notifyObservers(){
        for(Observer observer:observerCollection){
            observer.update();
        }
    };
}

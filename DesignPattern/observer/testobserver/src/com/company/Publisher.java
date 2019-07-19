package com.company;

public interface Publisher {
    void add(Observer observer);
    void delete(Observer observer);
    void notifyObserver();
}

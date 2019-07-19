package com.company;

public class AnnualSubscriber implements Observer {
    private String newString;
    private Publisher publisher;

    public AnnualSubscriber(Publisher publisher) {
        this.publisher = publisher;
        publisher.add(this);
    }

    @Override
    public void update(String title, String news) {
        this.newString = title + " : " + news;
        display();
    }

    private void display() {
        System.out.println("오늘 이야기 : "+this.newString);
    }
}

package com.company;

public class Main {

    public static void main(String[] args) {
        NewsMachine newsMachine = new NewsMachine();
        AnnualSubscriber as = new AnnualSubscriber(newsMachine);
        newsMachine.setNewsInfo("오늘 한파", "전국 영화 18도 입니다.");
    }
}

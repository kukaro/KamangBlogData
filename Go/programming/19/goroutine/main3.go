package main

import (
	"fmt"
	"time"
)

func sigma(start int, end int, c chan int) {
	sum := 0
	for i := start; i <= end; i++ {
		sum += i;
	}
	c <- sum;
}

func main() {
	var a int
	var b int
	//var c chan int= make(chan int)
	//var c = make(chan int)
	//c := make(chan int)
	var c chan int
	stime := time.Now();
	go sigma(100, 100000000, c)
	go sigma(10000, 314150000, c)
	a = <-c
	b = <-c
	etime := time.Now();
	fmt.Println(etime.Nanosecond() - stime.Nanosecond())
	fmt.Println(a)
	fmt.Println(b)
}

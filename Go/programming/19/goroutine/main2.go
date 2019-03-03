package main

import (
	"fmt"
)

func sigma(start int, end int, c chan int) {
	sum := 0
	for i := start; i <= end; i++ {
		sum += i
	}
	c <- sum
}

func main() {
	var a int
	var b int
	var d int
	//var c chan int= make(chan int)
	//var c = make(chan int)
	c := make(chan int)
	go sigma(1, 100, c)
	go sigma(101, 200, c)
	go sigma(101, 300, c)
	a, b,d = <-c, <-c,<-c
	fmt.Println(a + b + d)
}

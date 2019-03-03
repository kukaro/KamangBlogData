package main

import "fmt"

func sub(c chan int){
	c<-1
}

func main() {
	c := make(chan int)
	go sub(c)
	fmt.Println(<-c)
}

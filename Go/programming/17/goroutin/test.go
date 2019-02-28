package main

import (
	"fmt"
	"time"
)

var count int

func sub() {
	for i := 0; i < 50; i++ {
		count++
		time.Sleep(time.Second / 10)
		fmt.Printf("sub: %d\n", count)
	}
}

func main() {
	go sub()
	for i := 0; i < 50; i++ {
		count++
		time.Sleep(time.Second / 10)
		fmt.Printf("main: %d\n", count)
	}
}

package main

import (
	"fmt"
)

func sigma(start int, end int) int {
	sum := 0
	for i := start; i <= end; i++ {
		sum += i;
	}
	return sum;
}

func main() {
	var a int
	var b int
	a = sigma(1, 100);
	b = sigma(101, 200);
	fmt.Println(a + b)
}

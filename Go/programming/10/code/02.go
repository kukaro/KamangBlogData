package main

import "fmt"

func swap(x, y int) (int, int) {
	return y, x
}

func main() {
	a := 5
	b := 3
	fmt.Println(a, b)
	a, b = swap(a, b)
	fmt.Println(a, b)
}

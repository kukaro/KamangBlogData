package main

import "fmt"

func add(x int, y int) int {
	return x + y
}

func sub(x, y int) int {
	return x - y
}

func main() {
	a := 5
	b := 3
	fmt.Println(add(a, b))
	fmt.Println(sub(a, b))
}

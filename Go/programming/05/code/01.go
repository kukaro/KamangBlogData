package main

import "fmt"

func main() {
	var a int
	var b int
	fmt.Scan(&a, &b)
	if (a == b) {
		fmt.Println("a와 b는 같다.")
	}
	fmt.Print(a, b)
}

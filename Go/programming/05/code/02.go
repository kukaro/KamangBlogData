package main

import "fmt"

func main() {
	var a int
	var b int
	fmt.Scan(&a, &b)
	if (a == b) {
		fmt.Println("a와 b는 같다.")
	} else if (a > b) {
		fmt.Println("a는 b보다 크다.")
	} else if (a < b) {
		fmt.Println("a는 b보다 작다.")
	} else {
		fmt.Println("a와 b는 다르다.")
	}
	fmt.Print(a, b)
}

package main

import "fmt"

func main() {
	sum := 0
	i := 0
	for i <= 10 {
		sum += i
		i++
	}
	fmt.Print("합계는 ", sum, "입니다.\n")
}

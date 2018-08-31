package main

import "fmt"

func main() {
	var arr1 = make([]int, 5)
	for _, value := range arr1 {
		fmt.Print(value)
	}
}

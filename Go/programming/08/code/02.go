package main

import "fmt"

func main() {
	var arr1 = [5]int{1, 2, 3, 4, 5}
	arr1 = append(arr1, 6)
	for _, value := range arr1 {
		fmt.Print(value)
	}
}

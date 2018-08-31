package main

import "fmt"

func main() {
	arr1 := []int{1, 2, 3, 4, 5, 6}
	arr1_1 := arr1[:3]
	arr1_2 := arr1[3:]
	arr1_3 := arr1[2:5]

	for _, value := range arr1_1 {
		fmt.Print(value)
	}
	fmt.Println()
	for _, value := range arr1_2 {
		fmt.Print(value)
	}
	fmt.Println()
	for _, value := range arr1_3 {
		fmt.Print(value)
	}
}

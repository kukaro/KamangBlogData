package main

import "fmt"

func main() {
	var arr1 = [5]int{}
	arr2 := [...]int{2, 4, 6, 8, 10}
	for i := 0; i < len(arr1); i++ {
		fmt.Print("arr1[", i, "] = ", arr1[i], "\n")
	}
	fmt.Println()
	for index, value := range arr2 {
		fmt.Print("arr2[", index, "] = ", value, "\n")
	}
}

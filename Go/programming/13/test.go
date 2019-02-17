package main

import "fmt"

func main() {
	nums := make([]int,5)
	for key, value := range nums {
		fmt.Println(key, value)
	}
}
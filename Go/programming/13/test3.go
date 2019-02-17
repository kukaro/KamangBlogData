package main

import "fmt"

func main() {
	nums := map[string]string{"name": "kukaro", "age": "27"}
	for _, value := range nums {
		fmt.Println(value)
	}
}

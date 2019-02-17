package main

import "fmt"

func main() {
	nums := map[string]string{"name": "kukaro", "age": "27"}
	for key, value := range nums {
		fmt.Println(key, value)
	}
}

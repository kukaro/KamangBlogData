package main

import "fmt"

func main() {
	sum := 0
	i := 0
	for {
		sum += i
		i++
		fmt.Println(sum)
		if i%2 == 0 {
			continue
		}
		if i > 10 {
			break
		}
	}
}

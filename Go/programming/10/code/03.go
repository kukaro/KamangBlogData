package main

import "fmt"

func split(num int) (up, down int) {
	up = num / 10
	down = num % 10
	return
}

func main() {
	num := 17
	up, down := split(num)
	fmt.Println(up, down)

}

package main

import "fmt"

func main() {
	const a int = 10
	const b = 20
	const (
		sun = 0
		mon = 1
		tue = 2
		wed = 3
		thu = 4
		fri = 5
		sat = 6
	)
	fmt.Println(a, b)
	fmt.Println(sun, mon, tue, wed, thu, fri, sat)
}

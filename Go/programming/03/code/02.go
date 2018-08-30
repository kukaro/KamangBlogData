package main

import "fmt"

func main() {
	const (
		sun = iota
		mon
		tue
		wed
		thu
		fri
		sat
	)
	fmt.Println(sun, mon, tue, wed, thu, fri, sat)
}

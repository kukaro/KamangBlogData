package main

import (
	"fmt"
	)

type Point struct {
	X, Y float64
}

func main() {
	var v Point
	v = Point{3, 4}
	fmt.Println(v, v.X, v.Y)
}

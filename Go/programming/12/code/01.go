package main

import (
	"fmt"
)

type Point struct {
	X, Y float64
}

func main() {
	var p *Point
	p = &Point{1, 2}

	var p1 *Point = &Point{3,4}

	var p2 = &Point{5,6}

	p3 := &Point{7,8}
	fmt.Println(p, p.X, p.Y)
	fmt.Println(p1, p1.X, p1.Y)
	fmt.Println(p2, p2.X, p2.Y)
	fmt.Println(p3, p3.X, p3.Y)
}

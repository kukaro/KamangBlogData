package main

import (
	"fmt"
)

type Point struct {
	X, Y float64
}

func main() {
	p := Point{1, 2}
	q := &Point{3, 4}
	r := Point{X: 5}
	s := Point{}
	t := new(Point)
	fmt.Println(p)
	fmt.Println(q)
	fmt.Println(r)
	fmt.Println(s)
	fmt.Println(t)
}

package main

import (
	"fmt"
	)

type Point struct {
	PosX float64
	PosY float64
	posZ float64
}

func main() {
	var v Point
	v = Point{3, 4, 5}
	fmt.Println(v, v.PosX, v.PosY, v.posZ)
}

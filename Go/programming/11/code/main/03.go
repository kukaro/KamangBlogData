package main

import (
	"fmt"
	"../my"
	)

func main() {
	var v my.Point
	v = my.Point{3, 4, 5}
	fmt.Println(v, v.PosX, v.PosY, v.posZ)
}

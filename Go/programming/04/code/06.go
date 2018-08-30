package main

import "fmt"

func main() {
	a := 10
	b := 10
	c := 10
	d := 10
	e := 10
	f := 10
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(d)
	fmt.Println(e)
	fmt.Println(f)
	a = 3
	b += 3
	c -= 3
	d /= 3
	e *= 3
	f %= 3
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(d)
	fmt.Println(e)
	fmt.Println(f)
}

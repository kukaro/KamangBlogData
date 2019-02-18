package main

import "fmt"

func main() {
	add5 := outer(5)
	fmt.Println(add5(3))

	myFunc := func() string{
		return "hello"
	}

	yourFunc := func() func() string{
		return myFunc
	}
	fmt.Println(myFunc())
	fmt.Println(yourFunc()())
}

func outer(a int) func(int) int{
	return func (b int) int {
		return a+b
	}
}

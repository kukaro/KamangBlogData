package main

import "fmt"

func main() {
	var a int
	fmt.Print("0 과 90사이의 숫자를 입력하시오 : ")
	fmt.Scan(&a)
	switch {
	case a >= 90:
		fmt.Print("수")
	case a >= 80:
		fmt.Print("우")
	case a >= 70:
		fmt.Print("미")
	case a >= 60:
		fmt.Print("양")
	default:
		fmt.Print("가")
	}
	fmt.Println("입니다.")
}

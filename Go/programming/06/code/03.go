package main

import "fmt"

func main() {
	var a int
	fmt.Print("0 과 90사이의 숫자를 입력하시오 : ")
	fmt.Scan(&a)
	switch a / 10 {
	case 9:
		fmt.Print("수")
		fallthrough
	case 8:
		fmt.Print("우")
		fallthrough
	case 7:
		fmt.Print("미")
		fallthrough
	case 6:
		fmt.Print("양")
		fallthrough
	default:
		fmt.Print("가")
	}
	fmt.Println("입니다.")
}

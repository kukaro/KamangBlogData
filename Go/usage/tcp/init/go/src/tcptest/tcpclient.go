package main

import (
	"fmt"
	"net"
	"time"
)

func main() {
	client, err := net.Dial("tcp", "127.0.0.1:8000") // TCP 프로토콜, 127.0.0.1:8000 서버에 연결
	if err != nil {
		fmt.Println(err)
		return
	}
	defer client.Close() // main 함수가 끝나기 직전에 TCP 연결을 닫음

	go func(c net.Conn) {
		data := make([]byte, 4096) // 4096 크기의 바이트 슬라이스 생성

		for {
			n, err := c.Read(data) // 서버에서 받은 데이터를 읽음
			if err != nil {
				fmt.Println(err)
				return
			}

			fmt.Println(string(data[:n])) // 데이터 출력

			time.Sleep(1 * time.Second)
		}
	}(client)

	go func(c net.Conn) {
		i := 0
		for {
			fmt.Println("들어왔어용")
			//s := "Hello " + strconv.Itoa(i)
			var s1,s2 string
			fmt.Scanln(&s1,&s2)
			fmt.Println(s1)
			_, err := c.Write([]byte(s1)) // 서버로 데이터를 보냄
			if err != nil {
				fmt.Println("send")
				fmt.Println(err)
				fmt.Println("send")
				return
			}
			i++
			time.Sleep(1 * time.Second)
		}
	}(client)

	fmt.Scanln()
}
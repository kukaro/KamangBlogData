package main

import (
	"fmt"
	"net"
)

func requestHandler(conn net.Conn) {
	data := make([]byte, 4096)

	for {
		n, err := conn.Read(data)
		if err != nil {
			fmt.Println("에러남")
			fmt.Println(err)
			return
		}

		fmt.Println(string(data[:n]))
		fmt.Println("여기인가")

		_, err = c.Write(data[:n])
		if err != nil {
			fmt.Println(err)
			return
		}
	}
}

func main() {
	ln, err := net.Listen("tcp", ":8000") // TCP 프로토콜에 8000 포트로 연결을 받음
	if err != nil {
		fmt.Println(err)
		return
	}
	defer ln.Close() // main 함수가 끝나기 직전에 연결 대기를 닫음

	for {
		conn, err := ln.Accept() // 클라이언트가 연결되면 TCP 연결을 리턴
		if err != nil {
			fmt.Println(err)
			continue
		}
		defer conn.Close() // main 함수가 끝나기 직전에 TCP 연결을 닫음

		go requestHandler(conn) // 패킷을 처리할 함수를 고루틴으로 실행
	}
}
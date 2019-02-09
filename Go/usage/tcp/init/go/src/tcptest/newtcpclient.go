package main

import (
	"fmt"
	"log"
	"net"
	"time"
)

func main() {
	conn, err := net.Dial("tcp", ":5032")
	if nil != err {
		log.Fatalf("failed to connect to server")
	}

	// some event happens

	for {
		var s string
		fmt.Scanln(&s)
		fmt.Println(s)
		conn.Write([]byte(s))
		time.Sleep(time.Duration(3) * time.Second)
	}
}
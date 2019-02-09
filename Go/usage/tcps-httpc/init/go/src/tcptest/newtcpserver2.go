package main

import (
	"io"
	"log"
	"net"
)

func main() {
	l, err := net.Listen("tcp", ":8000")
	if nil != err {
		log.Println(err);
	}
	defer l.Close()

	for {
		conn, err := l.Accept()
		if nil != err {
			log.Println(err);
			continue
		}
		defer conn.Close()
		go ConnHandler(conn)
	}
}

func ConnHandler(conn net.Conn) {
	recvBuf := make([]byte, 4096)
	for {
		n, err := conn.Read(recvBuf)
		if nil != err {
			if io.EOF == err {
				log.Println(err);
				return
			}
			log.Println(err);
			return
		}
		if 0 < n {
			myResp := `HTTP/1.1 200 OK
Server: nginx
Date: Mon, 07 Sep 2015 10:39:12 GMT
Content-Type: application/json
Content-Length: 332
Connection: close
Access-Control-Allow-Origin: *
Access-Control-Allow-Credentials: true

{
  "name": "jiharu", 
  "age": "20000"
}`
			log.Println(myResp)
			_, err = conn.Write([]byte(myResp))
			conn.Close()
			if err != nil {
				log.Println(err)
				return
			}
		}
	}
}
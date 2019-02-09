package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	jsonBody := map[string]interface{}{}
	jsonBody["name"] = "kukaro"
	jsonBody["age"] = 26
	jsonStr, _ := json.Marshal(jsonBody)

	resp, _ := http.Post("http://localhost:8000","application/json; charset=UTF-8",bytes.NewBuffer([]byte(jsonStr)))
	fmt.Println(resp.Header)
	fmt.Println("**********")
	fmt.Println(resp)
	fmt.Println("**********")
	respBody, _ := ioutil.ReadAll(resp.Body)
	jsonData := map[string]interface{}{}
	json.Unmarshal(respBody, &jsonData)
	fmt.Println(jsonData)
}

package main

import "fmt"

func main() {
	mymap1 := map[string]string{}
	mymap2 := make(map[string]string)

	mymap1["aoa"] = "choa"
	mymap1["girlsday"] = "mina"
	mymap1["twice"] = "dahyun"

	mymap2["aoa"] = "jimin"
	mymap2["girlsday"] = "ura"
	mymap2["twice"] = "momo"

	for index, value := range mymap1 {
		fmt.Print(index, " ", value, "\n")
	}
	fmt.Println()
	for index, value := range mymap2 {
		fmt.Print(index, " ", value, "\n")
	}
}

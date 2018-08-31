package main

import "fmt"

func main() {
	mymap1 := map[string]string{
		"aoa":      "choa",
		"girlsday": "mina",
		"twice":    "dahyun",
	}

	mymap1["redvelvet"] = "irene"

	for index, value := range mymap1 {
		fmt.Print(index, " ", value, "\n")
	}
	fmt.Println()
}

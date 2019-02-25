package main

import "fmt"

func main()  {
	mymap := map[string]string{
		"aoa":      "choa",
		"girlsday": "mina",
		"twice":    "dahyun",
		"redvelvet": "irene",
	}

	delete(mymap, "twice")

	for index, value := range mymap {
		fmt.Print(index, " ", value, "\n")
	}
	fmt.Println()
}
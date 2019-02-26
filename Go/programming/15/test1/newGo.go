package main

import "fmt"

type Person struct {
	Name string
	Age int
}

type God struct {
	Person
	Good string
}

func (this Person) hisName() {
	fmt.Printf("his name is %s.\n", this.Name)
}

func (this Person) hisAge() {
	fmt.Printf("his age is %d.\n", this.Age)
}

type GetName interface {
	hisName()
}

type GetAge interface {
	hisAge()
}

type InfoPerson interface {
	GetName
	GetAge
}

func main()  {
	var i InfoPerson
	i = God{Person{"kukaro",27},"good"}
	i.hisName()
	i.hisAge()
}
package main

import (
	"github.com/labstack/echo"
	"net/http"
)

type User struct {
	Name   string
	Age    int
	gender string
}

func main() {
	e := echo.New()
	e.GET("/", getRoot)
	e.POST("/user", postUser)
	e.Logger.Fatal(e.Start(":1323"))
}

func getRoot(c echo.Context) error {
	return c.String(http.StatusOK, "Hello, World!")
}

func postUser(c echo.Context) error {
	user := User{"jiharu", 26, "male"}
	return c.JSON(http.StatusOK, user)
}

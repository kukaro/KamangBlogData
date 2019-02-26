package main

type Square struct {
	Width  float32
	Height float32
}

type Triangle struct {
	Width  float32
	Height float32
}

func (s Square) Area() float32 {
	return s.Width * s.Height
}

func (t Triangle) Area() float32 {
	return t.Width * t.Height / 2
}

type Line struct{
	Length float32
}

type Figure interface {
	Area() float32
}

//func main() {
//	f := make([]Figure, 0)
//	f = append(f, Square{2, 5})
//	f = append(f, Triangle{2, 5})
//	for _, value := range f {
//		fmt.Println(value.Area())
//	}
//
//}

package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int
	_, err := fmt.Scan(&a, &b)
	if err != nil {
		panic(err)
	}
	ans := math.Ceil(float64(b-1) / float64(a-1))
	fmt.Printf("%d\n", int(ans))
}

package main

import "fmt"

func main() {
	var k int
	_, err := fmt.Scan(&k)
	if err != nil {
		panic(err)
	}
	hour := 21 + k/60
	min := k % 60
	fmt.Printf("%02d:%02d\n", hour, min)
}

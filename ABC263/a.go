package main

import "fmt"

func isFullHouse(arr [5]int) bool {
	var count [13]int
	for _, v := range arr {
		count[v-1]++
	}
	ex2, ex3 := false, false
	for _, v := range count {
		ex2 = ex2 || v == 2
		ex3 = ex3 || v == 3
	}
	return ex2 && ex3
}

func main() {
	var a, b, c, d, e int
	_, err := fmt.Scanf("%d %d %d %d %d", &a, &b, &c, &d, &e)
	if err != nil {
		panic(err)
	}
	ans := isFullHouse([5]int{a, b, c, d, e})
	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

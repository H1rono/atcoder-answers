package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readLine(s *bufio.Scanner) string {
	s.Scan()
	return s.Text()
}

func solve(n int, x []int) int {
	scoreAt := func(p int) int {
		score := 0
		for i := 0; i < n; i++ {
			score += (x[i] - p) * (x[i] - p)
		}
		return score
	}
	x_mi, x_ma := x[0], x[0]
	for i := 1; i < n; i++ {
		if x[i] < x_mi {
			x_mi = x[i]
		}
		if x[i] > x_ma {
			x_ma = x[i]
		}
	}
	ans := scoreAt(x_ma)
	for p := x_mi; p < x_ma; p++ {
		s := scoreAt(p)
		if s < ans {
			ans = s
		}
	}
	return ans
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	l := readLine(s)
	n, err := strconv.Atoi(l)
	if err != nil {
		panic(err)
	}
	x := make([]int, n)
	l = readLine(s)
	splitted := strings.Split(l, " ")
	for i := 0; i < n; i++ {
		x[i], err = strconv.Atoi(splitted[i])
		if err != nil {
			panic(err)
		}
	}
	fmt.Println(solve(n, x))
}

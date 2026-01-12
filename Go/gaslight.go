package main
import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func getUserNumber(messege string) int {
	reader := bufio.NewReader(os.Stdin)
	valid := false
	convertedNumber := 0

	for !valid {
		fmt.Print(messege)
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)

		num, err := strconv.Atoi(input)
		if err != nil {
			fmt.Println("Enter an actual number Bozo ")
			continue
		}

		if num > int(math.MaxInt32) || num < int(math.MinInt32) {
			fmt.Println("Number too big Bozo ")
		} else {
			convertedNumber = num
			valid = true
		}
	}
	return convertedNumber
}

func insertValue (vec []int, n int) {
	howManyMore := n
	for a := 0 ; a < n; a++ {
		fmt.Printf("Enter a number for index %d (%d positions left)\n", a, howManyMore)
		vec[a] = getUserNumber("-> ")
		fmt.Println()
		howManyMore--
	}
}

func isSorted(vec []int) bool {
	return true
}

func main () {
	num_int := 0

	for num_int <= 0 {
		num_int = getUserNumber("How many integers do we want\n->")
		if num_int <= 0 {
			fmt.Print("Number has to be greater than zero bozo\n ")
		}
	}

	fmt.Println(num_int)

	vec := make([]int, num_int)
	insertValue(vec, num_int)

	for p:=0 ; p<num_int ; p++ {
		fmt.Println("index %d is %d\n", p, vec[p])
	}

	if isSorted(vec) {
		fmt.Println("This is sorted")
	} else {
		fmt.Println("Still sorted he he")
	}
}
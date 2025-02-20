package main

import "fmt"

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func Count(v []int, n int) int {
	count := 0
	for _, m := range v {
		if m == n {
			count++
		}
	}

	return count
}

func Equal(v1, v2 []int) bool {
	if len(v1) != len(v2) {
		return false
	}

	for _, n := range v1 {
		if Count(v1, n) != Count(v2, n) {
			return false
		}
	}

	return true
}

func Contains(vv [][]int, r []int) bool {
	for _, v := range vv {
		if Equal(v, r) {
			return true
		}
	}

	return false
}

func GetSubsets(vec []int, index int, r []int, result *[][]int) {
	if index == len(vec) {
		return
	}

	r = append(r, vec[index])

	if !Contains(*result, r) {
		*result = append(*result, r)
	}
	GetSubsets(vec, index+1, r, result)
	r = r[:len(r)-1]
}

func Subsets(A []int) [][]int {
	var result [][]int
	var r []int

	result = append(result, []int{})
	for i := 0; i < len(A); i++ {
		GetSubsets(A, i, r, &result)
	}
	return result
}

func main() {
	for {
		fmt.Print("Number of elements: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the array: ")
		result := Subsets(vec)

		for i := 0; i < len(result); i++ {
			fmt.Println(result[i])
		}
		fmt.Println("")
	}
}

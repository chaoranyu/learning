package main

import "fmt"

func main() {
    const LENGTH int = 10
    const WIDTH int = 5
    var area int
    const a, b, c = 1, false, "str"

    area = LENGTH * WIDTH
    fmt.Printf("Square: %d", area)
    fmt.Println()
    fmt.Println(a, b, c)
}

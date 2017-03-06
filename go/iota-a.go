package main

import "fmt"

func main() {
    const (
        a = iota    // 0
        b           // 1
        c           // 2
        d = "hi"    // hi   iota += 1
        e           // hi   iota += 1
        f = 100     // 100  iota += 1
        g           // 100  iota += 1
        h = iota    // 7    resume count
        i           // 8
    )

    fmt.Println(a, b, c, d, e, f, g, h, i)
}

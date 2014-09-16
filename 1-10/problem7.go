// A concurrent prime sieve

package main

import "fmt"

func Generate(ch chan<- int64) {
        var i int64 = 2
        for ; ; i++ {
                ch <- i // Send i to channel ch
        }
}

func Filter(in <-chan int64, out chan<- int64, prime int64) {
        for {
                i := <-in // recieve from in
                if i%prime != 0 {
                        out <- i // Send i to out
                }
        }
}

func fun(i int) {
        fmt.Println("nice")
}

func fun1(i int) {
        ls := []int{1, 2, 3, 4}
        for k := range ls {
                fmt.Println(k)
        }

}

func main() {
        ch := make(chan int64) // Creat a new channel
        go Generate(ch)
        for i := 0; i < 10001; i++ {
                prime := <-ch
                if i == 10000 {
                        fmt.Println(prime)
                }
                ch1 := make(chan int64)
                go Filter(ch, ch1, prime)
                ch = ch1
        }
}

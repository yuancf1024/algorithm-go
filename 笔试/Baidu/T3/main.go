package main
import "fmt"

func main() {
    n:=0
    ans:=0

	for {
		fmt.Scan(&n)
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				x := 0
				fmt.Scan(&x)
				ans = ans + x
			}
		}
		fmt.Printf("%d\n",ans)
		break
	}

}
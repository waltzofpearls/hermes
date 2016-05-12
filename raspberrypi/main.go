package main

import "log"

func main() {
	talkToArduino()
}

func talkToArduino() {
	a, err := NewArduino()
	if err != nil {
		log.Fatal(err)
	}
	log.Println("Ready to send commands...")

	output := a.Listen()
	serErr := a.WaitForStdin()

	for {
		select {
		case o := <-output:
			log.Println(o)
		case e := <-serErr:
			log.Fatalln(e)
		}
	}
}

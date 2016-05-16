package main

import (
	"log"
	"time"
)

func main() {
	// talkToArduino()

	c, err := NewCamera()
	if err != nil {
		log.Fatalln(err)
	}
	c.PanLeft(30)
	time.Sleep(time.Second)

	c.PanRight(30)
	time.Sleep(time.Second)

	c.ResetPosition()
}

func talkToArduino() {
	a, err := NewArduino()
	if err != nil {
		log.Fatalln(err)
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

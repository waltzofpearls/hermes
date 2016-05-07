package main

import (
	"bufio"
	"log"
	"time"

	"github.com/tarm/serial"
)

func main() {
	talkToArduino()
}

func talkToArduino() {
	// c := &serial.Config{Name: "/dev/tty.usbmodemFA131", Baud: 9600}
	c := &serial.Config{Name: "/dev/ttyACM0", Baud: 115200}
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
	}

	go func() {
		reader := bufio.NewReader(s)
		for {
			reply, _, err := reader.ReadLine()
			if err != nil {
				log.Fatal(err)
			}
			log.Println(string(reply))
			time.Sleep(5 * time.Millisecond)
		}
	}()

	_, err = s.Write([]byte("f\n"))
	if err != nil {
		log.Fatal(err)
	}

	time.Sleep(5 * time.Second)

	_, err = s.Write([]byte("s\n"))
	if err != nil {
		log.Fatal(err)
	}
}

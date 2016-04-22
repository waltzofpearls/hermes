package main

import (
	"bufio"
	"log"
	"time"

	"github.com/tarm/serial"
)

func main() {
	c := &serial.Config{Name: "/dev/tty.usbmodemFA131", Baud: 9600}
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
	}

	reader := bufio.NewReader(s)
	for {
		_, err = s.Write([]byte("test"))
		if err != nil {
			log.Fatal(err)
		}
		time.Sleep(time.Second)

		// _, err = s.Read(buf)
		// if err != nil {
		// 	log.Fatal(err)
		// }
		// log.Println(string(buf))

		// reply, err := reader.ReadBytes('\x0a')
		reply, _, err := reader.ReadLine()
		if err != nil {
			panic(err)
		}
		log.Println(string(reply))
	}
}

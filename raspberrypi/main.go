package main

import (
	"bufio"
	"log"
	"os"
	"time"
)

func main() {
	talkToArduino()
}

func talkToArduino() {
	a, err := NewArduino()
	if err != nil {
		log.Fatal(err)
	}

	time.Sleep(time.Second * 1)
	log.Println("Ready to send commands.")

	output := make(chan string)
	serErr := make(chan error)

	go func() {
		scanner := bufio.NewScanner(a.Serial)
		log.Println("Serial scanner started.")
		for scanner.Scan() {
			output <- scanner.Text()
		}
		log.Println("Serial scanner ended.")
	}()

	go func() {
		scanner := bufio.NewScanner(os.Stdin)
		for scanner.Scan() {
			if err := a.Send(scanner.Text()); err != nil {
				serErr <- err
			}
		}
	}()

	for {
		select {
		case o := <-output:
			log.Println(o)
		case e := <-serErr:
			log.Fatalln(e)
		}
	}
}

package main

import "log"

type DriveTrain struct{}

func (d *DriveTrain) initDriveTrain() {
	a, err := NewArduinoSerial()
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

func (d *DriveTrain) Forward() {
}

func (d *DriveTrain) Backward() {
}

func (d *DriveTrain) TurnLeft() {
}

func (d *DriveTrain) TurnRight() {
}

func (d *DriveTrain) Stop() {
}

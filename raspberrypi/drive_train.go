package main

import "log"

type DriveTrain struct {
	Ser    *ArduinoSerial
	SerErr <-chan error
	Output <-chan string
}

func (d *DriveTrain) initDriveTrain() {
	a, err := NewArduinoSerial()
	if err != nil {
		log.Fatalln(err)
	}

	d.Ser = a
	d.Output = a.Listen()
	d.SerErr = make(chan error)

	for {
		select {
		case o := <-d.Output:
			log.Println(o)
		case e := <-d.SerErr:
			log.Fatalln(e)
		}
	}
}

func (d *DriveTrain) Forward() {
	d.sendArduinoCommand("forward")
}

func (d *DriveTrain) Backward() {
	d.sendArduinoCommand("backward")
}

func (d *DriveTrain) TurnLeft() {
	d.sendArduinoCommand("turnleft")
}

func (d *DriveTrain) TurnRight() {
	d.sendArduinoCommand("turnright")
}

func (d *DriveTrain) Stop() {
	d.sendArduinoCommand("stop")
}

func (d *DriveTrain) sendArduinoCommand(cmd string) {
	if err := d.Ser.Send(cmd); err != nil {
		d.SerErr <- err
	}
}

func (d *DriveTrain) Debugging() {
	log.Println("Ready to send commands...")
	d.SerErr = d.Ser.WaitForStdin()
}

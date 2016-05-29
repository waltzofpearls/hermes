package main

import (
	"bufio"
	"errors"
	"io/ioutil"
	"os"
	"strings"
	"time"

	"github.com/tarm/serial"
)

const (
	ArduinoSerialBaud int = 115200
)

type ArduinoSerial struct {
	Serial *serial.Port
}

func NewArduinoSerial() (*ArduinoSerial, error) {
	a := &ArduinoSerial{}
	if err := a.initArduinoSerial(); err != nil {
		return nil, err
	}
	return a, nil
}

func (a *ArduinoSerial) initArduinoSerial() error {
	device, err := a.findArduino()
	if err != nil {
		return err
	}
	ser, err := serial.OpenPort(&serial.Config{
		Name: device,
		Baud: ArduinoSerialBaud,
	})
	if err != nil {
		return err
	}
	time.Sleep(time.Second * 1)
	a.Serial = ser
	return nil
}

func (a *ArduinoSerial) findArduino() (string, error) {
	devices, _ := ioutil.ReadDir("/dev")
	for _, d := range devices {
		if a.isArduino(d.Name()) {
			return "/dev/" + d.Name(), nil
		}
	}
	return "", errors.New("Cannot find Arduino device.")
}

func (a *ArduinoSerial) isArduino(device string) bool {
	return strings.Contains(device, "ttyACM") ||
		strings.Contains(device, "tty.usbmodem") ||
		strings.Contains(device, "tty.usbserial") ||
		strings.Contains(device, "ttyUSB")
}

func (a *ArduinoSerial) Listen() <-chan string {
	output := make(chan string)
	go func() {
		scanner := bufio.NewScanner(a.Serial)
		for scanner.Scan() {
			output <- scanner.Text()
		}
	}()
	return output
}

func (a *ArduinoSerial) Send(data string) error {
	_, err := a.Serial.Write([]byte(data + "\n"))
	if err != nil {
		return err
	}
	return nil
}

func (a *ArduinoSerial) WaitForStdin() <-chan error {
	serErr := make(chan error)
	go func() {
		scanner := bufio.NewScanner(os.Stdin)
		for scanner.Scan() {
			if err := a.Send(scanner.Text()); err != nil {
				serErr <- err
			}
		}
	}()
	return serErr
}

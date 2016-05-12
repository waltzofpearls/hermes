package main

import (
	"bufio"
	"errors"
	"io/ioutil"
	"strings"

	"github.com/tarm/serial"
)

const (
	ArduinoSerialBaud int = 115200
)

type Arduino struct {
	Serial *serial.Port
	Reader *bufio.Reader
}

func NewArduino() (*Arduino, error) {
	a := &Arduino{}
	return a.initSerial()
}

func (a *Arduino) initSerial() (*Arduino, error) {
	device, err := a.findArduino()
	if err != nil {
		return nil, err
	}
	a.Serial, err = serial.OpenPort(&serial.Config{
		Name: device,
		Baud: ArduinoSerialBaud,
	})
	if err != nil {
		return nil, err
	}
	a.Reader = bufio.NewReader(a.Serial)
	return a, nil
}

func (a *Arduino) findArduino() (string, error) {
	devices, _ := ioutil.ReadDir("/dev")
	for _, d := range devices {
		if a.isArduino(d.Name()) {
			return "/dev/" + d.Name(), nil
		}
	}
	return "", errors.New("Cannot find Arduino device.")
}

func (a *Arduino) isArduino(device string) bool {
	return strings.Contains(device, "ttyACM") ||
		strings.Contains(device, "tty.usbmodem") ||
		strings.Contains(device, "tty.usbserial") ||
		strings.Contains(device, "ttyUSB")
}

func (a *Arduino) Send(data string) error {
	_, err := a.Serial.Write([]byte(data + "\n"))
	if err != nil {
		return err
	}
	return nil
}

func (a *Arduino) Receive() (string, error) {
	reply, _, err := a.Reader.ReadLine()
	if err != nil {
		return "", nil
	}
	return string(reply), nil
}

func (a *Arduino) SendAndReceive(data string) (string, error) {
	if err := a.Send(data); err != nil {
		return "", nil
	}
	return a.Receive()
}

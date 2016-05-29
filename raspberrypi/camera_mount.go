package main

import "github.com/waltzofpearls/go-servo-picobber"

const (
	PwmFrequency     uint8 = 60
	ServoChannelPan  uint8 = 8
	ServoChannelTilt uint8 = 0

	PanMin int = 130
	PanMid int = 380
	PanMax int = 630

	TiltMin int = 260
	TiltMid int = 420
	TiltMax int = 580
)

type CameraMount struct {
	Servo *servo.Servo
}

func NewCameraMount() (*CameraMount, error) {
	c := &initCameraMount{}
	if err := c.init(); err != nil {
		return nil, err
	}
	return c, nil
}

func (c *CameraMount) initCameraMount() error {
	sv, err := servo.NewServo()
	if err != nil {
		return err
	}
	sv.SetPwmFreq(60)
	c.Servo = sv
	return nil
}

func (c *CameraMount) PanLeft(pos int) error {
	newVal := c.scaleNumber(pos, 0, 90, PanMin, PanMid)
	if err := c.Servo.SetPwm(ServoChannelPan, 0, newVal); err != nil {
		return err
	}
	return nil
}

func (c *CameraMount) PanRight(pos int) error {
	newVal := c.scaleNumber(pos, 0, 90, PanMid, PanMax)
	if err := c.Servo.SetPwm(ServoChannelPan, 0, newVal); err != nil {
		return err
	}
	return nil
}

func (c *CameraMount) TiltUp(pos int) error {
	newVal := c.scaleNumber(pos, 0, 90, TiltMid, TiltMax)
	if err := c.Servo.SetPwm(ServoChannelTilt, 0, newVal); err != nil {
		return err
	}
	return nil
}

func (c *CameraMount) TiltDown(pos int) error {
	newVal := c.scaleNumber(pos, 0, 90, TiltMin, TiltMid)
	if err := c.Servo.SetPwm(ServoChannelTilt, 0, newVal); err != nil {
		return err
	}
	return nil
}

func (c *CameraMount) scaleNumber(valueIn, baseMin, baseMax, limitMin, limitMax int) int {
	if valueIn < baseMin {
		valueIn = baseMin
	}
	if valueIn > baseMax {
		valueIn = baseMax
	}
	return ((limitMax - limitMin) * (valueIn - baseMin) / (baseMax - baseMin)) + limitMin
}

func (c *CameraMount) ResetPosition() error {
	if err := c.Servo.SetPwm(ServoChannelPan, 0, PanMid); err != nil {
		return err
	}
	if err := c.Servo.SetPwm(ServoChannelTilt, 0, TiltMid); err != nil {
		return err
	}
	return nil
}

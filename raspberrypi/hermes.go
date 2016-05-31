package main

type Hermes struct {
	DriveTrain
	CameraMount
	VideoStream
	WifiDirect
}

func NewHermes() (h *Hermes, err error) {
	h := &Hermes{}
	if err = h.initDriveTrain(); err != nil {
		return
	}
	if err = h.initCameraMount(); err != nil {
		return
	}
	if err = h.initVideoStream(); err != nil {
		return
	}
	if err = h.initWifiDirect(); err != nil {
		return
	}
	return
}

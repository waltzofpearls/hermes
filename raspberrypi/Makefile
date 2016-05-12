.PHONY: all

all: build

VENDOR_FLAG = GO15VENDOREXPERIMENT=1
GO_CMD = $(VENDOR_FLAG) godep go
PKG = $$(go list ./... | grep -v /vendor/)

build: *.go
	$(GO_CMD) build -o hermes ./

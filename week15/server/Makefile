all: build_dir server

build_dir:
	mkdir -p build

server:
	cd build && cmake .. && make

clean:
	rm -rf build
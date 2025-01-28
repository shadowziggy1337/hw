all: build_dir client

build_dir:
	mkdir -p build

client:
	cd build && cmake .. && make

clean:
	rm -rf build
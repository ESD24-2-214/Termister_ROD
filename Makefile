##
# Rotaing Donut
#
# @file
# @version 0.1

all: build run monitor

clean:

build:
	# When building include all files
	export PLATFORMIO_BUILD_FLAGS="-DDEBUG_MONITOR"
	# echo $$PLATFORMIO_BUILD_FLAGS
	pio run

run:
	pio run -t upload

test1:

	export PLATFORMIO_BUILD_FLAGS="-DDEBUG_MONITOR"
	echo $$PLATFORMIO_BUILD_FLAGS

monitor:
	pio device monitor  --raw

file:
	pio run -t upload
	rm -f data.tmp
	touch data.tmp
	pio device monitor > data.tmp


# end

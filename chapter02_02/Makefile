# Makefile homework 2
# Based on build spec for Windows
#
CFLAGS := -Wall -Wextra -pedantic -mmcu=atmega328p -fsigned-char -O3 -fno-exceptions
CPPFLAGS := -std=c++11 -fno-rtti -fstrict-enums -fno-use-cxa-atexit -fno-use-cxa-get-exception-ptr -fno-nonansi-builtins -fno-threadsafe-statics -fno-enforce-eh-specs
CINCLUDES := -I./

all: compile hex_file list_file size_information name_information demangled_names
	@echo "---------------------------------"
	@echo "Make all complete - program size:"
	@cat bin/led_size.txt
	@echo "---------------------------------"
	

upload: bin/led.hex
	avrdude -pm328p -carduino -P/dev/tty.usbmodemfd131 -D -Uflash:w:bin/led.hex:a -C/Volumes/crosspi/avrtools/etc/avrdude.conf
#	avrdude -p atmega328p -c arduino -P  /dev/tty.usbmodemfa141 -U flash:w:bin/led.hex:a

compile: clean create_dir led.elf
	@echo "Compile success"

create_dir:
	mkdir bin

clean:
	rm -rf bin/

led.elf: avr.ld bin/crt0.o bin/led.o
	avr-g++ -mmcu=atmega328p -nostartfiles -nostdlib -Wl,-Tavr.ld,-Map,bin/led.map bin/led.o bin/crt0.o -o bin/led.elf

bin/crt0.o: crt0.s
	avr-g++ -mmcu=atmega328p -fsigned-char -x assembler crt0.s -c -o bin/crt0.o
	
bin/led.o: led.cpp
	avr-g++ -mmcu=atmega328p -fsigned-char -std=c++11 -I. -c led.cpp -o bin/led.o
	
hex_file: bin/led.elf
	avr-objcopy -O ihex bin/led.elf bin/led.hex
	
list_file: 
	avr-objdump -h -S bin/led.elf > bin/led.lss

size_information: 
	avr-size -A -t bin/led.elf > bin/led_size.txt

name_information:
	avr-nm --numeric-sort --print-size bin/led.elf > bin/led_nm.txt

demangled_names:
	avr-nm --numeric-sort --print-size bin/led.elf | avr-c++filt > bin/led_cppfilt.txt


# This Makefile was created based on the build.bat provided by Christopher Kormanyos.
# This is the Makefile for chapter02_03 folder

CFLAGS := -Wall -Wextra -pedantic -mmcu=atmega328p -fsigned-char -O3 -fno-exceptions
CPPFLAGS := -std=c++11 -fno-rtti -fstrict-enums -fno-use-cxa-atexit -fno-use-cxa-get-exception-ptr -fno-nonansi-builtins -fno-threadsafe-statics -fno-enforce-eh-specs
CINCLUDES := -Isrc/ -Isrc/mcal/avr -Isrc/util/STL -Isrc/util/STL_C++11_Compatibility -Isrc/util/STL_C++14_Compatibility

upload: bin/chapter02_03.hex
	avrdude -v -p atmega328p -c arduino -P /dev/tty.usbmodemfa141 -U flash:w:bin/chapter02_03.hex:i

compile: very_clean fetch chapter02_03.elf
	@echo "Everything seems to have compiled..."
	@echo "Try to upload the code using avrdude..."

fetch:
	mkdir bin

clean:
	rm bin/*.o
	rm bin/chapter02_03*.*

very_clean:
	rm -rf bin/

chapter02_03.elf: target/micros/avr/make/avr.ld bin/mcal.o bin/mcal_gcc_cxx_completion.o bin/mcal_cpu.o bin/mcal_gpt.o bin/mcal_irq.o bin/mcal_led.o bin/sys_start.o bin/crt0.o bin/crt0_init_ram.o bin/crt1.o bin/int_vect.o
	avr-g++ -x none -mrelax -nostartfiles $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -Wl,--gc-sections -Wl,-Ttarget/micros/avr/make/avr.ld,-Map,bin/chapter02_03.map bin/mcal.o bin/mcal_gcc_cxx_completion.o bin/mcal_cpu.o bin/mcal_gpt.o bin/mcal_irq.o bin/mcal_led.o bin/sys_start.o bin/crt0.o bin/crt0_init_ram.o bin/crt1.o bin/int_vect.o -o bin/chapter02_03.elf

bin/mcal.o: src/mcal/mcal.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/mcal/mcal.cpp -o bin/mcal.o

bin/mcal_gcc_cxx_completion.o: src/mcal/mcal_gcc_cxx_completion.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/mcal/mcal_gcc_cxx_completion.cpp -o bin/mcal_gcc_cxx_completion.o

bin/mcal_cpu.o: src/mcal/avr/mcal_cpu.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/mcal/avr/mcal_cpu.cpp -o bin/mcal_cpu.o

bin/mcal_gpt.o: src/mcal/avr/mcal_gpt.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/mcal/avr/mcal_gpt.cpp -o bin/mcal_gpt.o

bin/mcal_irq.o: src/mcal/avr/mcal_irq.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/mcal/avr/mcal_irq.cpp -o bin/mcal_irq.o

bin/mcal_led.o: src/mcal/avr/mcal_led.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/mcal/avr/mcal_led.cpp -o bin/mcal_led.o

bin/sys_start.o: src/sys/start/sys_start.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/sys/start/sys_start.cpp -o bin/sys_start.o

bin/crt0.o: target/micros/avr/startup/crt0.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c target/micros/avr/startup/crt0.cpp -o bin/crt0.o

bin/crt0_init_ram.o: target/micros/avr/startup/crt0_init_ram.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c target/micros/avr/startup/crt0_init_ram.cpp -o bin/crt0_init_ram.o

bin/crt1.o: target/micros/avr/startup/crt1.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c target/micros/avr/startup/crt1.cpp -o bin/crt1.o

bin/int_vect.o: target/micros/avr/startup/int_vect.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c target/micros/avr/startup/int_vect.cpp -o bin/int_vect.o

hex_file: bin/chapter02_03.elf
	avr-objcopy -O ihex bin/chapter02_03.elf bin/chapter02_03.hex

list_file: bin/chapter02_03.elf
	avr-size -A -t bin/chapter02_03.elf > bin/chapter02_03.txt

size_information: bin/chapter02_03.elf
	avr-nm --numeric-sort --print-size bin/chapter02_03.elf > bin/chapter02_03_nm.txt

name_information: bin/chapter02_03.elf
	avr-nm --numeric-sort --print-size bin/chapter02_03.elf > bin/chapter02_03_nm.txt

demangled_names: bin/chapter02_03.elf
	avr-nm --numeric-sort --print-size bin/chapter02_03.elf | avr-c++filt > bin/chapter02_03_cppfilt.txt

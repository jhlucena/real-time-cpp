# This Makefile was created based on the build.bat provided by Christopher Kormanyos.
# This is the Makefile for chapter02_03a folder

CFLAGS := -Wall -Wextra -pedantic -mmcu=atmega328p -fsigned-char -O2 -fno-exceptions
CPPFLAGS := -std=c++11 -fno-rtti -fstrict-enums -fno-use-cxa-atexit -fno-use-cxa-get-exception-ptr -fno-nonansi-builtins -fno-threadsafe-statics -fno-enforce-eh-specs
CINCLUDES := -Isrc -Isrc/mcal/avr -Isrc/util/STL -Isrc/util/STL_C++11_Compatibility -Isrc/util/STL_C++17_Compatibility

upload: bin/chapter02_03a.hex
	avrdude -v -p atmega328p -c arduino -P /dev/tty.usbmodemfd131 -U flash:w:bin/chapter02_03a.hex:i

compile: very_clean fetch chapter02_03a.elf
	@echo "Everything seems to have compiled..."
	@echo "Try to upload the code using avrdude..."

fetch:
	mkdir bin

clean:
	rm bin/*.o
	rm bin/chapter02_03a*.*

very_clean:
	rm -rf bin/

chapter02_03a.elf: bin/app_led.o bin/mcal.o bin/mcal_gcc_cxx_completion.o bin/mcal_cpu.o bin/mcal_gpt.o bin/mcal_irq.o bin/mcal_led.o bin/mcal_osc.o bin/mcal_port.o bin/mcal_wdg.o bin/os.o bin/os_task_control_block.o bin/sys_idle.o bin/sys_mon.o bin/sys_start.o bin/crt0.o bin/crt0_init_ram.o bin/crt1.o bin/int_vect.o
	avr-g++ -x none -mrelax -nostartfiles $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) --gc-sections -Wl,-Ttarget/micros/avr/make/avr.ld,-Map,bin/chapter02_03a.map bin/app_led.o bin/mcal.o bin/mcal_gcc_cxx_completion.o bin/mcal_cpu.o bin/mcal_gpt.o bin/mcal_irq.o bin/mcal_led.o bin/mcal_osc.o bin/mcal_port.o bin/mcal_wdg.o bin/os.o bin/os_task_control_block.o bin/sys_idle.o bin/sys_mon.o bin/sys_start.o bin/crt0.o bin/crt0_init_ram.o bin/crt1.o bin/int_vect.o -o bin/chapter02_03a.elf


bin/mcal_osc.o: src/mcal/avr/mcal_osc.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/mcal/avr/mcal_osc.cpp -o bin/mcal_osc.o

bin/app_led.o: src/app/led/app_led.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/app/led/app_led.cpp -o bin/app_led.o

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

bin/mcal_port.o: src/mcal/avr/mcal_port.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/mcal/avr/mcal_port.cpp -o bin/mcal_port.o

bin/mcal_wdg.o: src/mcal/avr/mcal_wdg.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/mcal/avr/mcal_wdg.cpp -o bin/mcal_wdg.o

bin/os.o: src/os/os.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/os/os.cpp -o bin/os.o

bin/os_task_control_block.o: src/os/os_task_control_block.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/os/os_task_control_block.cpp -o bin/os_task_control_block.o

bin/sys_idle.o: src/sys/idle/sys_idle.cpp 
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/sys/idle/sys_idle.cpp -o bin/sys_idle.o

bin/sys_mon.o: src/sys/mon/sys_mon.cpp
	avr-g++ -x c++ $(CFLAGS) $(CPPFLAGS) $(CINCLUDES) -c src/sys/mon/sys_mon.cpp -o bin/sys_mon.o

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

hex_file: bin/chapter02_03a.elf
	avr-objcopy -O ihex bin/chapter02_03a.elf bin/chapter02_03a.hex

list_file: bin/chapter02_03.elf
	avr-size -A -t bin/chapter02_03a.elf > bin/chapter02_03a.txt

size_information: 
	avr-size -A -t bin/chapter02_03a.elf > bin/chapter02_03a_size.txt

name_information:
	avr-nm --numeric-sort --print-size bin/chapter02_03a.elf > bin/chapter02_03a_nm.txt

demangled_names:
	avr-nm --numeric-sort --print-size bin/chapter02_03a.elf | avr-c++filt > bin/chapter02_03a_cppfilt.txt
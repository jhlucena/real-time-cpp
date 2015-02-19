/*
 * port_pin.h
 *
 *  Created on: Feb 16, 2015
 *      Author: josemhernandezlucena
 */

#ifndef SRC_APP_GPIO_PORT_PIN_H_
#define SRC_APP_GPIO_PORT_PIN_H_

#include <cstdint>
#include <mcal/mcal_reg_access_template.h>

template<typename addr_type, typename reg_type, const addr_type port, const reg_type bpos>
class port_pin {
public:
	static void set_direction_output()
	{
		//Set port as output
		port_dir_type::bit_set();
	}

	static void set_direction_input()
	{
		//Set port as input
		port_dir_type::bit_clr();
	}

	static void set_pin_high()
	{
		//Set port pin high
		port_pin_type::bit_set();
	}

	static void set_pin_low()
	{
		//Set port pin low
		port_pin_type::bit_clr();
	}

	static bool read_input_value()
	{
		// Read port input value
		return port_inp_type::bit_get();
	}

	static void toggle()
	{
		// Toggle output value
		port_pin_type::bit_not();
	}

private:
	static constexpr addr_type pdir = port - 1U;
	static constexpr addr_type pinp = port - 2U;

	typedef mcal::reg::access<addr_type, reg_type, port, bpos> port_pin_type;
	typedef mcal::reg::access<addr_type, reg_type, pdir, bpos> port_dir_type;
	typedef mcal::reg::access<addr_type, reg_type, pinp, bpos> port_inp_type;
};



#endif /* SRC_APP_GPIO_PORT_PIN_H_ */

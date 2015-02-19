/*
 * led_port.h
 *
 *  Created on: Feb 15, 2015
 *      Author: josemhernandezlucena
 */

#include "led_base.h"
#include "../gpio/port_pin.h"

#ifndef SRC_APP_LED_LED_PORT_H_
#define SRC_APP_LED_LED_PORT_H_

template<typename addr_type, typename reg_type, const addr_type addr,
			const reg_type bpos>
class led_port: public led_base
{
public:

	explicit led_port()
	{
		// Set the port as pin output, low
		port_pin_type::set_pin_low();
		port_pin_type::set_direction_output();
	}

	virtual ~led_port() { }

	virtual void toggle(void) {
		// Toggle led
		if(is_on) {
			port_pin_type::set_pin_low();
		} else {
			port_pin_type::set_pin_high();
		}
		is_on = !is_on;
	}

private:
	typedef port_pin<addr_type, reg_type, addr, bpos> port_pin_type;
};



#endif /* SRC_APP_LED_LED_PORT_H_ */

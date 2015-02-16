/*
 * led_port.h
 *
 *  Created on: Feb 15, 2015
 *      Author: josemhernandezlucena
 */

#include <cstdint>
#include "led_base.h"

#ifndef SRC_APP_LED_LED_PORT_H_
#define SRC_APP_LED_LED_PORT_H_

class led_port: public led_base
{
public:
	typedef std::uint8_t port_type;
	typedef std::uint8_t bval_type;

	led_port(const port_type p, const bval_type b): port(p), bval(b)
	{

	}

	virtual ~led_port() { }

	virtual void toggle(void) {
		// Toggle led
		*reinterpret_cast<volatile bval_type*>(port) ^= bval;
		is_on = !is_on;
	}

private:
	const port_type port;
	const bval_type bval;

};



#endif /* SRC_APP_LED_LED_PORT_H_ */

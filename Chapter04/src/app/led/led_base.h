/*
 * led_base.h
 *
 *  Created on: Feb 15, 2015
 *      Author: josemhernandezlucena
 */

#ifndef SRC_APP_LED_LED_BASE_H_
#define SRC_APP_LED_LED_BASE_H_

#include <cstdint>

class led_base
{
public:
	virtual void toggle() = 0;  // pure abstract
	virtual ~led_base() { }     // Virtual Destructor

	// Interface for querying state
	bool state_is_on() const { return is_on; }

protected:
	bool is_on;
	led_base() : is_on(false) {}

private:
	// Private non-implemented copy constructor
	led_base(const led_base&) = delete;

	// Private non-implemented copy assignment constructor
	const led_base& operator=(const led_base&) = delete;
};


#endif /* SRC_APP_LED_LED_BASE_H_ */

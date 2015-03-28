/*
 * pwm_type.h
 *
 *  Created on: Feb 16, 2015
 *      Author: josemhernandezlucena
 */

#ifndef SRC_APP_PWM_TYPE_H_
#define SRC_APP_PWM_TYPE_H_
#include <cstdint>
#include <atomic>
#include <algorithm>
#include "../gpio/port_pin.h"

template<typename addr_type, typename reg_type, const addr_type addr,
		const reg_type bpos, const std::uint8_t resol = 100U>
class pwm_type {

public:
	pwm_type(const std::uint8_t duty = 0U) :
			counter(0U), duty_cycle(duty), shadow(duty) {
		// Set the pin to output, low
		port_pin_type::set_pin_low();
		port_pin_type::set_direction_output();
	}

	void set_duty(const uint8_t duty) {
		// Set duty cycle on the shadow register
		std::atomic_store(&shadow, std::min(duty, resol));
	}

	std::uint8_t get_duty() const {
		return std::atomic_load(&duty_cycle);
	}

	void service() {
		// Increment counter
		++counter;

		// Set output according to duty_cycle
		if (counter <= duty_cycle) {
			port_pin_type::set_pin_high();
		} else {
			port_pin_type::set_pin_low();
		}

		if (counter >= resol) {
			// Latch duty cycle from shadow register
			duty_cycle = shadow;
			// Reset counter for new pwm period
			counter = 0U;
		}
	}

private:
	std::uint8_t counter;
	volatile std::uint8_t duty_cycle;
	std::uint8_t shadow;

	typedef port_pin<addr_type, reg_type, addr, bpos> port_pin_type;
	pwm_type(const pwm_type&) = delete;
	const pwm_type& operator=(const pwm_type&) = delete;
};

#endif /* SRC_APP_PWM_TYPE_H_ */

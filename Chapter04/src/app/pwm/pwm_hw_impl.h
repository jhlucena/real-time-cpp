/*
 * pwm_hw_impl.h
 *
 *  Created on: Feb 22, 2015
 *      Author: josemhernandezlucena
 *  Implement PWM through hardware
 */
#include <cstdint>
#include "pwm_base.h"
#include <mcal/mcal_reg_access_template.h>


#ifndef SRC_APP_PWM_PWM_HW_IMPL_H_
#define SRC_APP_PWM_PWM_HW_IMPL_H_

// Defines for bits... later set on mcal_reg or other header...(cleanup)
/////// Name   bit on register TCCR0A
#define WGM00  0
#define WGM01  1
#define COM0A1 7
#define COM0A0 6
#define COM0B1 5
#define COM0B0 4

/////// Name   bit on register TCCR0B
#define F0C0A  7
#define F0C0B  6
#define WGM02  3
#define CS02   2
#define CS01   1
#define CS00   0



enum PWM_8BIT_PORTS {
	PWM_A=0,
	PWM_B
} ;



template<typename pwm_type, typename addr_type, typename reg_type>
class pwm_hw_impl: pwm_base<pwm_type> {

public:

	pwm_hw_impl(const PWM_8BIT_PORTS pwmport) {

		port = pwmport;
		// Create masks
		constexpr std::uint8_t tccra_mask = (1 << COM0A1) | (1 << COM0A0) | (0 << COM0B0) | (0 << COM0B1) | (1 << WGM00);
		constexpr std::uint8_t tccrb_mask = (1 << WGM02) | (1 << CS00 );

		// Set TCCR1A and TCCR1B register masks
		// Set registers TCCR0A and TCCR0B
		mcal::reg::access<addr_type, reg_type, mcal::reg::tccr0a, tccra_mask>::reg_set(); // Set tccr0a
		mcal::reg::access<addr_type, reg_type, mcal::reg::tccr0b, tccrb_mask>::reg_set(); // Set tccr0b

		// Clear TCNT0
		mcal::reg::access<addr_type, reg_type, mcal::reg::tcnt0, UINT8_C(0)>::reg_set(); // clear TCNT0

		// Select port and pin depending on enum....
		if(pwmport == PWM_A)
		{
			typedef mcal::reg::access<addr_type, reg_type, mcal::reg::portd, UINT8_C(6)> port_pin_type;
			typedef mcal::reg::access<addr_type, reg_type, mcal::reg::portd -1U, UINT8_C(6)> port_dir_type;
			// Set the PWM register, first set port to output, low
			port_dir_type::bit_set(); // Set port output
			port_pin_type::bit_clr(); // Set pin low
			mcal::reg::access<addr_type, reg_type, mcal::reg::ocr0a, UINT8_C(0)>::reg_set(); // Clear OCR0A

		}
		else
		{
			// Set ports d, pin 6 as pwm_a
			typedef mcal::reg::access<addr_type, reg_type, mcal::reg::portd, UINT8_C(6)> port_pin_type;
			typedef mcal::reg::access<addr_type, reg_type, mcal::reg::portd -1U, UINT8_C(5)> port_dir_type;
			// Set the PWM register, first set port to output, low
			port_dir_type::bit_set(); // Set port output
			port_pin_type::bit_clr(); // Set pin low
			mcal::reg::access<addr_type, reg_type, mcal::reg::ocr0b, UINT8_C(0)>::reg_set(); // clear OCR0B
		}

	}

	virtual ~pwm_hw_impl() {};

	void set_duty(const uint8_t duty) {

		// Set duty cycle
		if(port == PWM_A)
			*reinterpret_cast<volatile reg_type*>(mcal::reg::ocr0a)  = duty;
		else
			*reinterpret_cast<volatile reg_type*>(mcal::reg::ocr0b)  = duty;
	}

	std::uint8_t get_duty() const {
		if(port == PWM_A)
			return mcal::reg::access<addr_type, reg_type, mcal::reg::ocr0a>::reg_get();
		else
			return mcal::reg::access<addr_type, reg_type, mcal::reg::ocr0b>::reg_get();
	}




private:
	pwm_hw_impl(const PWM_8BIT_PORTS, const pwm_hw_impl&) = delete;
	const pwm_hw_impl& operator=(const pwm_hw_impl&) = delete;
	PWM_8BIT_PORTS port;

};




#endif /* SRC_APP_PWM_PWM_HW_IMPL_H_ */

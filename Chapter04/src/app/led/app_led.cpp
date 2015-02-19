///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2013.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// This code is modified using book code to demonstrate the software PWM described
// on chapter 9 of the book.
//

#include <mcal/mcal.h>
#include <util/utility/util_time.h>
#include "led_port.h"
#include "led_pwm.h"
#include "../pwm/pwm_type.h"

namespace app {

	// These app task functions inside namespace
	//
	namespace tasks {
		void task_init();
		void task_func();
	}

	// LED's connected to digital ports implementation
	//
	namespace ledPort {

		typedef led_port<std::uint8_t, std::uint8_t, mcal::reg::portb, UINT8_C(1)> ledPortB_1;
		typedef led_port<std::uint8_t, std::uint8_t, mcal::reg::portd, UINT8_C(7)> ledPortD_7;

		ledPortB_1 led_b1;
		ledPortD_7 led_d7;

	}

	// LED's connected to PWM software implementation
	//
	namespace ledPwm {

	// Declare a PWM...
	typedef pwm_type<std::uint8_t, std::uint8_t, mcal::reg::portb, UINT8_C(0)> pwm_0;
	pwm_0 pwm0;

	// Create the led_pwm...
	typedef led_pwm< pwm_type<std::uint8_t, std::uint8_t, mcal::reg::portb, UINT8_C(0)>,
					&pwm0 > pwm_led_b0;
	pwm_led_b0 led_pwm_b0;

	// Declare a PWM...
	typedef pwm_type<std::uint8_t, std::uint8_t, mcal::reg::portb, UINT8_C(2)> pwm_1;
	pwm_1 pwm1;

	// Create the led_pwm...
	typedef led_pwm< pwm_type<std::uint8_t, std::uint8_t, mcal::reg::portb, UINT8_C(2)>,
					&pwm1 > pwm_led_b1;
	pwm_led_b1 led_pwm_b1;
	}


	namespace {
	typedef util::timer<std::uint32_t> timer_type;

		// Port toggle timer every second
		timer_type app_led_timer(timer_type::seconds(1U));

		// PWM service rate timer to produce a PWM signal at 1us
		timer_type app_pwm_timer(timer_type::microseconds(1U));

		// Dimming timer (250 milliseconds)
		timer_type app_dim_timer(timer_type::microseconds(1000U));
	}
}

void app::tasks::task_init() {
// any needed app init
}

void app::tasks::task_func() {

	static volatile std::uint8_t counter = 0;
	// Service togglers
	if (app_led_timer.timeout()) {
		app::ledPort::led_b1.toggle();    // Toggle on port B, pin 1
		app::ledPort::led_d7.toggle();    // Toggle on port D, pin 7
		app::ledPwm::led_pwm_b1.toggle(); // Toggle on PWM signal on port B, pin 2

		app_led_timer.start_interval(timer_type::seconds(1U));
	}

	// Service dimmer
	if(app_dim_timer.timeout())
	{
		app::ledPwm::led_pwm_b0.dimming(counter++);
		if(counter == 101)
			counter = 0;

		app_dim_timer.start_interval(timer_type::microseconds(200U));

	}

	// Service the PWM signals at 1us
	if (app_pwm_timer.timeout()) {
		app::ledPwm::pwm0.service();
		app::ledPwm::pwm1.service();
		app_pwm_timer.start_interval(timer_type::microseconds(1U));
	}

}

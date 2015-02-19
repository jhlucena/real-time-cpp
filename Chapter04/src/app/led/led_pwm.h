/*
 * led_pwm.h
 *
 *  Created on: Feb 16, 2015
 *      Author: josemhernandezlucena
 */

#ifndef SRC_APP_LED_LED_PWM_H_
#define SRC_APP_LED_LED_PWM_H_
#include "led_base.h"
#include "../pwm/pwm_type.h"


template< typename pwm_element,
		 pwm_element *pwm>
class led_pwm: public led_base
{
public:

	explicit led_pwm()
	{
	}

	virtual ~led_pwm() {}

	virtual void toggle()
	{
		// toggle led with pwm signal
		is_on = (pwm_impl->get_duty() > 0U);
		pwm_impl->set_duty(is_on ? 0U : 100U);
		is_on = !is_on;
	}

	void dimming(const std::uint8_t duty)
	{
		pwm_impl->set_duty(duty);
		is_on = (duty != 0U);
	}

private:
	pwm_element* pwm_impl = pwm;

};



#endif /* SRC_APP_LED_LED_PWM_H_ */

/*
 * pwm_base.h
 *
 *  Created on: Feb 22, 2015
 *      Author: josemhernandezlucena
 *  Define basic pwm functionality to be implemented
 *  by SW or HW PWM children classes
 */

#ifndef SRC_APP_PWM_PWM_BASE_H_
#define SRC_APP_PWM_PWM_BASE_H_

template<typename type>
class pwm_base {

public:
	virtual ~pwm_base() {};
    virtual void set_duty(const type val) = 0;
	virtual type get_duty() const = 0;

protected:
	const type duty;
	pwm_base() : duty(0U) { }

private:
	// Private non-implemented copy constructor
	pwm_base(const pwm_base&) = delete;

	// Private non-implemented copy assignment constructor
	const pwm_base& operator=(const pwm_base&) = delete;

};
#endif /* SRC_APP_PWM_PWM_BASE_H_ */

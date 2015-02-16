
///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2013.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal/mcal.h>
#include <util/utility/util_time.h>
#include "led_port.h"

namespace app
{
  namespace led
  {
    void task_init();
    void task_func();

     led_port led_b0 {
    	mcal::reg::portb,
		mcal::reg::bval0
    };

     led_port led_d7 {
    	mcal::reg::portd,
		mcal::reg::bval7
    };
  }
}

namespace
{
  typedef util::timer<std::uint32_t> timer_type;
  timer_type app_led_timer(timer_type::seconds(1U));
}

void app::led::task_init()
{
  //mcal::led::led0.toggle();
  app::led::led_b0.toggle();

}

void app::led::task_func()
{
  if(app_led_timer.timeout())
  {
	app::led::led_b0.toggle();
    app_led_timer.start_interval(timer_type::seconds(1U));
    app::led::led_d7.toggle();

    //mcal::led::led0.toggle();
  }
}

#include "../h/main.h"

void stop();

/// DO NOT DELETE THIS METHOD
/// It is called every 1ms and e.g. can be used for implementing a
/// real time counter / clock.
void user_1ms_isr_type2(void) {
}

void ecrobot_device_initialize(void) {
}

void ecrobot_device_terminate(void) {
}

void hello_world() {
	ecrobot_status_monitor("Hello, World!");

}

void forward_expanded(int speed, int dist)
{
	nxt_motor_set_speed(NXT_PORT_A, speed, 0);
	nxt_motor_set_speed(NXT_PORT_B, speed, 0);
}

void rotate(int degree) {
	nxt_motor_set_count(NXT_PORT_A, degree*5+nxt_motor_get_count(NXT_PORT_A));
	nxt_motor_set_count(NXT_PORT_B, -(degree*5)-nxt_motor_get_count(NXT_PORT_B));

	stop();
}

void stop() {
	nxt_motor_set_speed(NXT_PORT_A, 0, 1);
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
}

TASK(OSEK_Main_Task) {
	hello_world();
	//typedef enum direction {NORTH, SOUTH, WEST, EAST};

	/*typedef struct field
	{
		int fn, fs, fw, fe, fexp, ftok;
	};*/

	forward_expanded(72,100);
	while(!ecrobot_get_touch_sensor(NXT_PORT_S1))
	{
		if(ecrobot_get_touch_sensor(NXT_PORT_S1))
		{
			stop();
		}
	}
		/* 500msec wait */
		systick_wait_ms(500);


}

#include "superkarel.h"


int check_beeper() {
	if(beepers_present()) {
		pick_beeper();
		return 1;
	}
	else {
		return 0;
	}
}


void turn_right() {
	turn_left();
	turn_left();
	turn_left();
}


int check_wall_right() {
	while (true) {
		if (facing_east()) {
			return 1;
		}
		else {
			turn_left();
		}
	}
	return 0;
}

void go_back() {
		check_wall_right();
		turn_left();
		pick_beeper();
		while (true) {
			if (front_is_blocked() && left_is_clear()) {
				turn_left();
			}
			else if (front_is_blocked() && left_is_blocked() && right_is_blocked()) {
				turn_right();
				break;
			}
			else {
				step();
			}
		}
	
}

int check_botom() {
	while (true) {
		
		if (beepers_present()) {
			return 1;
		}
	
		if (facing_south() && !front_is_blocked()) {
			step();
		}
		else if (facing_south() && front_is_blocked()) {
			break;
		}
		else {
			turn_left();
		}
	}
	return 0;
}


void go_up() {
	while (true) {
		if (check_wall_right() && front_is_blocked()) {
			turn_left();
			step();
		}

		else {
			step();
			break;
		}
	}
}


void go_front() {
	while (true) {
		if (front_is_clear() || front_is_blocked()) {

			if (check_botom()) {
				go_back();
				break;
			}
			else {
				go_up();
			}
		}
		else {
			step();
		}
	}
}


int main() {
	set_step_delay(100);
	turn_on("task_1.kw");
	go_front();
	turn_off();
	return 0;
}

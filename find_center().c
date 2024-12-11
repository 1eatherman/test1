#include <superkarel.h>

void move_forward();
void check_direction();
void turn_right();
void move_steps();
void adjust_position();

int main() {
    set_step_delay(50);
    turn_on("task_5.kw");

    // Face west and move forward until hitting a wall
    while (!facing_west()) {
        turn_left();
    }
    while (front_is_clear()) {
        step();
    }

    // Face south and move forward until hitting a wall
    while (!facing_south()) {
        turn_left();
    }
    while (front_is_clear()) {
        step();
    }

    turn_left();

    // Place beepers in required positions
    while (!beepers_present()) {
        if (!front_is_clear() && !right_is_clear()) {
            put_beeper();
            turn_left();
            step();
        }
        else if (!front_is_clear() && !left_is_clear()) {
            put_beeper();
            turn_right();
            step();
        }
        else if (front_is_clear()) {
            put_beeper();
            step();
        }
    }

    // Adjust direction after placing beepers
    while (!front_is_clear()) {
        turn_left();
    }

    if (facing_north()) {
        check_direction();
        move_forward();
    } else {
        move_forward();
        check_direction();
    }

    // Face north again before turning off
    while (!facing_north()) {
        turn_left();
    }

    turn_off();
    return 0;
}

void turn_right() {
    turn_left();
    turn_left();
    turn_left();
}

void check_direction() {
    while (!facing_north()) {
        turn_left();
    }
    step();
    step();
    if (front_is_clear()) {
        check_direction();
    }
    adjust_position();
}

void adjust_position() {
    while (!facing_south()) {
        turn_left();
    }
    step();
}

void move_forward() {
    step();
    step();
    if (front_is_clear()) {
        move_forward();
    }
    move_steps();
}

void move_steps() {
    while (!facing_west()) {
        turn_left();
    }
    step();
}


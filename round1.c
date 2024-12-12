#include <stdbool.h>

void turn_to_south(){
    while(not_facing_south()){
        turn_left();
    }
}

void mark_empty_line(){

    turn_left();
    turn_left();

    while(front_is_clear()){
        step();
    }

    turn_left();
    turn_left();
    put_beeper();

    while(front_is_clear()){
        step();
        put_beeper();
    }
}

bool no_beepers(){
    if(no_beepers_present() && no_beepers_in_bag()){
        return 1;
    }
    else{
        return 0;
    }
}

//pick_all

void go_check(){
    while(true){
        if(beepers_is_present()){
            while(beeper_present()){
                pick_beeper();
            }
        }
        else if(front_is_clear()){
            step();
        }
        else if(front_is_blocked()){
            if(beepers_is_present()){
                pick_beeper();
            }
            break;
        }
    }
}

int check_end(){
    if(front_is_blocked() && right_is_blocked()){
        return 1;
    }
    else if(front_is_blocked() && left_is_blocked()){
        return 1;
    }
    else{
        return 0;
    }
}

void pick_all(){
    while(not_facing_west()){
        tern_left();
    }

    while(front_is_clear()){
        step();
    }

    turn_left();

    while(front_is_clear()){
        step();
    }

    turn_left();

    while(true){
        go_check();

        if(check_end()){
            break;
        }
        else{
            if(facing_west()){
                turn_left();
                turn_left();
                turn_left();
                step();
                turn_left();
                turn_left();
                turn_left();
            }
            else if(facing_east()){
                turn_left();
                step();
                turn_left();
            }
        }
    }
}

//end

void find_south_east(){
    while(not_facing_south()){
        turn_left();
    }

    while(front_is_clear()){
        step();
    }

    while(not_facint_east()){
        turn_left();
    }

    while(front_is_clear()){
        step();
    }

    turn_left();
    turn_left();
}

bool facing_vertical(){
    if(facing_north() || facing_south()){
        return true;
    }
    else{
        return false;
    }
}

//void_climb_stairs()

void climb_stairs(){
    while(not_facing_east()){
        turn_left();
    }

    while(true){
        if(front_is_clear()){
            while(front_is_clear()){
                if(beepers_present()){
                    while(beepers_present()){
                        pick_beeper();
                    }
                }
                step();
                if(facing_east() && right_is_clear()){
                    break;
                }
            }
            if(facing_east() && right_is_clear()){
                turn_left();
                turn_left();
                step();
                turn_left();
                turn_left();
                break;
            }
        }

        else if(front_is_blocked() && left_is_clear()){
            turn_left();
            while(front_is_clear() && right_is_blocked()){
                step();
            }
            turn_left();
            turn_left();
            turn_left();
            step();
        }
    }
}

//end

//chessboard

void go_put_b(){
    put_beeper();
    while(front_is_clear()){
        step();
        put_beeper();
    }
}

void go_put_w(){
    while(front_is_clear()){
        step();
        put_beeper();
    }
}

void go_back_cb(){
    turn_left();
    turn_left();
    while(front_is_clear()){
        step();
    }
}

int turn_and_check(){
    turn_left();
    turn_left();
    turn_left();
    if(front_is_blocked()){
        return 1;
    }
    else{
        step();
        turn_left();
        turn_left();
        turn_left();
        return 0;
    }
}

void chessboard(){
    while(true){
        go_put_b();
        go_back_cb();
        if(turn_and_check()){
            break;
        }
        go_put_w();
        go_back_cd();
        if(turn_and_check()){
            break;
        }
    }
}

//end

//x-mas
void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void go_l_xmas(){
    turn_left();
    while(true){
        step();
        turn_right();
        step();
        if(right_is_clear() && front_is_clear()){
            put_beeper();
            put_beeper();
            step();
            turn_right();
            step();
            put_beeper();
            turn_left();
            break;
        }
        put_beeper();
        turn_left();
    }
}

void go_r_xmas(){
    while(true){
        step();
        if(front_is_blocked() && right_is_blocked()){
            breake();
        }
        turn_right();
        step();
        turn_left();
        put_beeper();
    }

}
void x_mas(){
    go_l_xmas();
    go_r_xmas();
    pick_beeper();
    while(front_is_clear()){
        step();
    }
}

//end

void devide_even_beepers(){
    step();

    while(beepers_present()){
        pick_beepers();
    }

    while(beepers_in_bag()){
        put_beeper();
        step();
        put_beeper();
        turn_left();
        turn_left();
        step();
        turn_left();
        turn_left();
    }

    turn_left();
    turn_left();
    step();
    turn_left();
    turn_left();
}

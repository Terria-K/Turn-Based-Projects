use std::{thread::sleep, time::Duration, io, ops::Range};
use rand::{thread_rng, Rng};

use crate::entity::*;

#[derive(PartialEq)]
enum ArenaStates {
    IdleState,
    TurnAState,
    TurnBState,
    FinalState
}

pub struct Arena<'a> {
    contestant_a: &'a mut Entity,
    contestant_b: &'a mut Entity,
    state: ArenaStates
}

impl<'a> Arena<'a> {
    pub fn new(contestant_a: &'a mut Entity, contestant_b: &'a mut Entity) -> Arena<'a> {
        Arena {
            contestant_a,
            contestant_b,
            state: ArenaStates::IdleState
        }
    }

    pub fn fight(&mut self) {
        let randomize = thread_rng().gen_range::<i32, Range<i32>>(0..2);
        self.state = match randomize {
            1 => ArenaStates::TurnAState,
            _ => ArenaStates::TurnBState
        };
        let mut turn = 1;
        while self.state != ArenaStates::FinalState {
            let a_damage = assign_attack_damage(50);
            let b_damage = assign_attack_damage(50);

            match self.state {
                ArenaStates::TurnAState => {
                    { deal_damage_to(self.contestant_a, &mut self.contestant_b, a_damage); }                        
                    self.display_health();
                    println!("============Turn {}===============", turn);
                    if self.contestant_b.hp > 0 {
                        println!("{} Turn!", self.contestant_b.name);
                    }
                    self.state = ArenaStates::TurnBState;
                },
                ArenaStates::TurnBState => {
                    { deal_damage_to(self.contestant_b, &mut self.contestant_a, b_damage); }                        
                    self.display_health();
                    println!("============Turn {}===============", turn);
                    if self.contestant_a.hp > 0 {
                        println!("{} Turn!", self.contestant_a.name);
                    }
                    self.state = ArenaStates::TurnAState;
                },
                _ => {}
            }

            if self.contestant_a.hp < 1 {
                println!("{} Wins!", self.contestant_b.name);
                self.state = ArenaStates::FinalState;
                continue;
            }

            if self.contestant_b.hp < 1 {
                println!("{} Wins!", self.contestant_a.name);
                self.state = ArenaStates::FinalState;
                continue;
            }

            turn += 1;
            sleep(Duration::from_millis(1000));
        }
        self.prompt();
    }

    fn prompt(&mut self) {
        println!("===================================");
        println!("Type 0 or above to continue the game, type -1 to exit!");
        // Compiler won't shut up, even though it was used
        let mut _num = 0;
        loop {       
            let mut input = String::new();
            if let Ok(_) = io::stdin().read_line(&mut input) {
                let split = input
                    .split_ascii_whitespace()
                    .next()
                    .unwrap_or("NaN");
                match split.parse() {
                    Ok(inp) => {
                        _num = inp;
                        break;
                    },
                    Err(_) => {
                        println!("{} is not a valid number", input);
                    }
                }
            }
        }
        if _num <= -1 {
            return;
        }
        self.contestant_a.hp = 100;
        self.contestant_b.hp = 100;
        self.fight();
    }

    fn display_health(&self) {
        println!("{} has {} hp.", self.contestant_a.name, self.contestant_a.hp); 
        println!("{} has {} hp.", self.contestant_b.name, self.contestant_b.hp); 
    }
}
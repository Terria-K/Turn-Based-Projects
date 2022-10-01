use std::{thread::sleep, time::Duration, io, ops::Range};
use rand::{thread_rng, Rng};

use crate::entity::*;

#[derive(PartialEq)]
enum States {
    Idle,
    TurnA,
    TurnB,
    Final
}

pub struct Arena {
    entity_a: Entity,
    entity_b: Entity,
    state: States
}

impl Arena {
    pub fn new(entity_a: Entity, entity_b: Entity) -> Arena {
        Arena {
            entity_a,
            entity_b,
            state: States::Idle
        }
    }

    pub fn fight(&mut self) {
        let randomize = thread_rng().gen_range::<i32, Range<i32>>(0..2);
        self.state = match randomize {
            1 => States::TurnA,
            _ => States::TurnB
        };
        let mut turn = 1;
        while self.state != States::Final {
            let a_damage = assign_attack_damage(50);
            let b_damage = assign_attack_damage(50);

            match self.state {
                States::TurnA => {
                    self.entity_a.deal_damage_to(&mut self.entity_b, a_damage);                       
                    self.display_health();
                    println!("============Turn {}===============", turn);
                    if self.entity_b.hp > 0 {
                        println!("{} Turn!", self.entity_b.name);
                    }
                    self.state = States::TurnB;
                },
                States::TurnB => {
                    self.entity_b.deal_damage_to(&mut self.entity_a, b_damage); 
                    self.display_health();
                    println!("============Turn {}===============", turn);
                    if self.entity_a.hp > 0 {
                        println!("{} Turn!", self.entity_a.name);
                    }
                    self.state = States::TurnA;
                },
                _ => {}
            }

            if self.entity_a.hp < 1 {
                println!("{} Wins!", self.entity_b.name);
                self.state = States::Final;
                continue;
            }

            if self.entity_b.hp < 1 {
                println!("{} Wins!", self.entity_a.name);
                self.state = States::Final;
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
        let mut input = String::new();
        if io::stdin().read_line(&mut input).is_ok() {
            let num = input.trim().parse::<i32>().unwrap_or(-1);
            if num > -1 {
                self.entity_a.hp = 100;
                self.entity_b.hp = 100;
                self.fight();
            }
        }
    }

    fn display_health(&self) {
        println!("{} has {} HP.", self.entity_a.name, self.entity_a.hp); 
        println!("{} has {} HP.", self.entity_b.name, self.entity_b.hp); 
    }
}
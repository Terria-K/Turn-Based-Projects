use std::io;

use entity::*;
use arena::*;

mod entity;
mod arena;

fn main() {
    let mut player = Entity::new("Player");
    let mut enemy = Entity::new("Enemy");
    let mut input = String::new();
    println!("Enter any key to start!");
    match io::stdin().read_line(&mut input) {
        Ok(_) => {
            let mut arena = Arena::new(&mut player, &mut enemy);
            arena.fight();
        },
        Err(_) => {
            println!("Invalid operation!");
        },
    }
}
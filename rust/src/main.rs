use std::io;

use entity::*;
use arena::*;

mod entity;
mod arena;

fn main() {
    let player = Entity::new("Player");
    let enemy = Entity::new("Enemy");
    let mut input = String::new();
    println!("Enter any key to start!");
    if io::stdin().read_line(&mut input).is_ok() {
        let mut arena = Arena::new(player, enemy);
        arena.fight();
    }
}
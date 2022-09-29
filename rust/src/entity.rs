use rand::Rng;

pub struct Entity {
    pub name: String,
    pub hp: i8
}

impl Entity {
    pub fn new(name: &str) -> Entity {
        Entity { 
            name: name.into(), 
            hp: 100 
        }
    }

    pub fn deal_damage_to(&self, target: &mut Entity, damage: i8) {
        target.hp -= damage;
        println!("{} Damages -> {} with {} dmg", self.name, target.name, damage);
        println!("===============================");
    }
}

pub fn assign_attack_damage(max: i8) -> i8 {
    rand::thread_rng().gen_range(0..max)
}

impl Default for Entity {
    fn default() -> Self {
        Entity { 
            name: "NoNamed Entity".into(), 
            hp: 100 
        }
    }
}
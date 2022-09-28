from __future__ import annotations
from random import randrange 

class Entity:
    def __init__(self, name) -> None:
        self.name = name
        self.hp = 100

    def deal_damage_to(self, entity: Entity, damage: int):
        entity.hp -= damage
        print("{0} Damages => {1} with {2} dmg".format(self.name, entity.name, damage))
    
    def assign_attack_damage(self, max: int) -> int:
        return randrange(max)
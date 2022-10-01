from random import randrange
from time import sleep

from entity import Entity

idle_state = 0
turn_a_state = 1
turn_b_state = 2
final_state = 3

class Arena:
    def __init__(self, entity_a: Entity, entity_b: Entity) -> None:
        self.entity_a = entity_a
        self.entity_b = entity_b
        self.state = idle_state

    def fight(self):
        randomize = randrange(2)
        self.state = turn_a_state if randomize == 1 else turn_b_state

        turn = 1
        while self.state != final_state:
            a_damage = self.entity_a.assign_attack_damage(50)
            b_damage = self.entity_b.assign_attack_damage(50)
            
            print("============Turn %s===============" % turn)

            if self.state == turn_a_state:
                self.entity_a.deal_damage_to(self.entity_b, a_damage)
                self.display_health()
                if self.entity_b.hp > 0:
                    print("%s Turn!\n" % self.entity_b.name)
                self.state = turn_b_state
            elif self.state == turn_b_state:
                self.entity_b.deal_damage_to(self.entity_a, b_damage)
                self.display_health()
                if self.entity_a.hp > 0:
                    print("%s Turn!\n" % self.entity_a.name)
                self.state = turn_a_state
            
            if self.entity_a.hp < 1:
                self.state = final_state
                print("%s Wins!" % self.entity_b.name)

            if self.entity_b.hp < 1:
                self.state = final_state
                print("%s Wins!" % self.entity_a.name)
            turn += 1
            sleep(1)

        self.prompt()

    def display_health(self):
        print("{0} has {1} HP".format(self.entity_a.name, self.entity_a.hp))
        print("{0} has {1} HP".format(self.entity_b.name, self.entity_b.hp))

    def prompt(self):
        inp = input("Type 0 or above to continue the game, type -1 to exit")
        if inp > -1:
            self.entity_a = 100
            self.entity_b = 100
            self.fight()

import random
import time
from arena import Arena
from entity import Entity

random.seed(time.time())

player = Entity("Player")
enemy = Entity("Enemy")
input("Enter any key to start!")
arena = Arena(player, enemy)
arena.fight()
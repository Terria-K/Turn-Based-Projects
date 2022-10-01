<?php

class Entity {
    public $name;
    public $hp;

    function __construct($name) {
        $this->name = $name;
        $this->hp = 100;
    }

    function deal_damage_to(Entity $entity, $damage) {
        $entity->hp -= $damage;
        echo $this->name." Damages -> ".$entity->name." with ".$damage." dmg\n";
        echo "===============================\n";
    }

    function assign_attack_damage($max): int {
        return rand(0, $max);
    }
}
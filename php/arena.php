<?php
enum States {
    case IdleState;
    case TurnAState;
    case TurnBState;
    case FinalState;
}

class Arena {
    private $entity_a;
    private $entity_b;
    private $state;

    function __construct($entity_a, $entity_b) {
        $this->entity_a = $entity_a;
        $this->entity_b = $entity_b;
        $this->state = States::IdleState;
    }

    function fight() {
        $randomize = rand(0, 2);
        $this->state = $randomize == 1 ? States::TurnAState : States::TurnBState;
        $turn = 1;

        while ($this->state != States::FinalState) {
            $a_damage = $this->entity_a->assign_attack_damage(50);
            $b_damage = $this->entity_b->assign_attack_damage(50);

            echo "============Turn ".$turn."===============\n";
            switch ($this->state) {
                case States::TurnAState:
                    $this->entity_a->deal_damage_to($this->entity_b, $a_damage);
                    $this->display_health();
                    if ($this->entity_b->hp > 0) {
                        echo $this->entity_b->name." Turn!\n\n";
                    }
                    $this->state = States::TurnBState;
                    break;
                case States::TurnBState:
                    $this->entity_b->deal_damage_to($this->entity_a, $b_damage);
                    $this->display_health();
                    if ($this->entity_a->hp > 0) {
                        echo $this->entity_a->name." Turn!\n\n";
                    }
                    $this->state = States::TurnAState;
                    break;
            }

            if ($this->entity_a->hp < 1) {
                $this->state = States::FinalState;
                echo $this->entity_b->name." Wins!\n";
            }

            if ($this->entity_b->hp < 1) {
                $this->state = States::FinalState;
                echo $this->entity_a->name." Wins!\n";
            }

            $turn += 1;
            sleep(1);
        }

        $this->prompt();
    }

    private function display_health() {
        echo $this->entity_a->name." has ".$this->entity_a->hp." HP\n";
        echo $this->entity_b->name." has ".$this->entity_b->hp." HP\n";
    }

    private function prompt() {
        $inp = intval(readline("Type 0 or above to continue the game, type -1 to exit\n"));
        if ($inp > -1) {
            $this->entity_a->hp = 100;
            $this->entity_b->hp = 100;
            $this->fight();
        }
    }
}
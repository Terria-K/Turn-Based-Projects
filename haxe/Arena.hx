package;
import Random;
import Entity;

enum States {
    IdleState;
    TurnAState;
    TurnBState;
    FinalState;
}

class Arena {
    private var entityA: Entity;
    private var entityB: Entity;
    private var state: States;

    public function new(entityA: Entity, entityB: Entity) {
        this.entityA = entityA;
        this.entityB = entityB;
        state = States.IdleState;
    }

    public function fight() {
        final randomize = Random.int(0, 2);
        switch randomize {
            case 1: state = States.TurnBState;
            case _: state = States.TurnAState;
        }

        var turn = 1;
        while (state != States.FinalState) {
            var aDamage = entityA.assignAttackDamage(50);
            var bDamage = entityB.assignAttackDamage(50);

            switch (state) {
                case States.TurnAState:
                    entityA.dealDamageTo(entityB, aDamage);
                    displayHealth();
                    trace('============Turn $turn===============');
                    if (entityB.hp > 0) {
                        trace('${entityB.name} Turn!');
                    }
                    state = States.TurnBState;
                case States.TurnBState:
                    entityB.dealDamageTo(entityA, bDamage);
                    displayHealth();
                    trace('============Turn $turn===============');
                    if (entityA.hp > 0) {
                        trace('${entityA.name} Turn!');
                    }
                    state = States.TurnAState;
                case _:
            }

            if (entityA.hp < 1) {
                state = FinalState;
                trace('${entityB.name} Wins!');
                continue;
            }
            if (entityB.hp < 1) {
                state = FinalState;
                trace('${entityA.name} Wins!');
                continue;
            }

            turn++;
            Sys.sleep(1);
        }
        prompt();
    }

    private function displayHealth() {
        trace('${entityA.name} has ${entityA.hp} health');
        trace('${entityB.name} has ${entityB.hp} health'); 
    }

    private function prompt() {
        trace("Type 0 or above to continue the game, type -1 to exit!");
        var line = Sys.stdin().readLine();
        var num = Std.parseInt(line);
        if (num != null && num > -1) {
            entityA.hp = 100;
            entityB.hp = 100;
            fight();
            return;
        }
    }
}
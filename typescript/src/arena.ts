import { assignAttackDamage, dealDamage, Entity } from "./entity";

type Arena = {
    entityA: Entity,
    entityB: Entity,
    states: States
}

enum States {
    IdleState = 0,
    TurnAState = 1,
    TurnBState = 2,
    FinalState = 3
}

export function newArena(a: Entity, b: Entity): Arena {
    return {
        entityA: a,
        entityB: b,
        states: States.IdleState
    }
}

export function* fight(self: Arena) {
    const randomize = Math.ceil(Math.random() * 1);
    switch (randomize) {
        case 0:
            self.states = States.TurnAState;
        case 1:
            self.states = States.TurnBState;
    }

    let turn = 1;
    
    while (self.states != States.FinalState) {
        const aDamage = assignAttackDamage(50);
        const bDamage = assignAttackDamage(50);

        switch (self.states) {
            case States.TurnAState:
                dealDamage(self.entityA, self.entityB, aDamage);
                displayHealth(self);
                console.log(`============Turn ${turn}===============\n`)
                if (self.entityB.hp > 0)
                    console.log(`${self.entityB.name} Turn!\n`);
                self.states = States.TurnBState;
            case States.TurnBState:
                dealDamage(self.entityB, self.entityA, bDamage);
                displayHealth(self);
                console.log(`============Turn ${turn}===============\n`)
                if (self.entityA.hp > 0)
                    console.log(`${self.entityA.name} Turn!\n`);
                self.states = States.TurnAState;
        }

        if (self.entityA.hp < 1) {
            self.states = States.FinalState;
            console.log(`${self.entityB.name} Wins!\n`);
            break;
        }

        if (self.entityB.hp < 1) {
            self.states = States.FinalState;
            console.log(`${self.entityA.name} Wins!\n`);
            break;
        }

        turn++;
        yield;
    }
}


function displayHealth(self: Arena) {
    console.log(`${self.entityA.name} has ${self.entityA.hp} health`);
    console.log(`${self.entityB.name} has ${self.entityB.hp} health`);
}

function prompt() {

}
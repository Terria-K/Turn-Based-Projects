export interface Entity {
    name: string,
    hp: number,
}

export function newEntity(name: string): Entity {
    return {
        name: name,
        hp: 100
    }
}

export function dealDamage(dealer: Entity, target: Entity, damage: number) {
    target.hp -= damage;
    console.log(`${dealer.name} Damage <>> ${target.name} with ${damage} dmg\n`);
    console.log("===============================\n");
}

export function assignAttackDamage(max: number) {
    return Math.ceil(Math.random() * max);
}
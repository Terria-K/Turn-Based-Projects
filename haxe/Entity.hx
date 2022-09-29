package;
import Random;

class Entity {
    public var name: String;
    public var hp: Int;

    public function new(name: String) {
        this.name = name;
        this.hp = 100;
    }

    public function dealDamageTo(target: Entity, damage: Int) {
        target.hp -= damage;
        trace('$name Damages => ${target.name} with $damage dmg');     
        trace("===============================");
    }

    public function assignAttackDamage(max: Int): Int {
        return Random.int(0, max);
    }
}
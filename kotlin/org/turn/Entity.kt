package org.turn


data class Entity(val name: String) {
    var hp: Int = 100
    fun dealDamageTo(entity: Entity, damage: Int) {
        entity.hp -= damage
        println("%s Damages -> %s with %d dmg".format(this.name, entity.name, damage))
        println("===============================")
    }
    
    fun assignAttackDamage(max: Int): Int {
        return (0..max).random()
    }
}
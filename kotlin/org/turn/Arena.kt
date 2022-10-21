package org.turn

enum class States { Idle, TurnA, TurnB, Final }

class Arena(val entityA: Entity, val entityB: Entity) {
     var gameState = States.Idle
     
     fun fight() {
         var randomize = (0..2).random()
         gameState = when (randomize) {
             1 -> States.TurnB
             else -> States.TurnA
         }
         var turn = 1
         while (gameState != States.Final) {
            var aDamage = entityA.assignAttackDamage(50)
            var bDamage = entityB.assignAttackDamage(50)
            println("============Turn %d===============".format(turn))
             
            when (gameState) {
                 States.TurnA -> {
                     entityA.dealDamageTo(entityB, aDamage)
                     displayHealth()
                     if (entityB.hp > 0) {
                         println("%s Turn!".format(entityB.name))
                     }
                     gameState = States.TurnB
                 }
                 States.TurnB -> {
                     entityB.dealDamageTo(entityA, bDamage)
                     displayHealth()
                     if (entityA.hp > 0) {
                         println("%s Turn!".format(entityA.name))
                     }
                     gameState = States.TurnA
                 } 
                 else -> {}
            }
            
            if (entityA.hp < 1) {
                gameState = States.Final
                println("%s Wins!".format(entityB.name))
                continue
            }
            if (entityB.hp < 1) {
                gameState = States.Final
                println("%s Wins!".format(entityA.name))
                continue
            }
            
            turn++
            Thread.sleep(1000)
        }
        prompt()
    }
    
    fun displayHealth() {
        println("%s has %d HP".format(entityA.name, entityA.hp))
        println("%s has %d HP".format(entityB.name, entityB.hp))
    }
    
    fun prompt() {
        println("Type 0 or above to continue the game, type -1 to exit!")
        var num = readLine()
        try {
            var input = num?.toInt()
            if (input != null && input > -1) {
                entityA.hp = 100
                entityB.hp = 100
                fight()
            }
        } catch (e: NumberFormatException) {
            println("Not a valid number")
        }

    }
}
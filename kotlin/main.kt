import org.turn.Entity
import org.turn.Arena

fun main() {
    var player = Entity("Player")
    var enemy = Entity("Enemy")
    
    println("Enter any key to start!")
    readLine()
    var arena = Arena(player, enemy)
    arena.fight()
}
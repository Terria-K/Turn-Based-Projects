import Entity;
import Arena;

class Main {
    static function main() {
        final player = new Entity("Player");
        final enemy = new Entity("Enemy");
        trace("Enter any key to start!");
        Sys.stdin().readLine();
        final arena = new Arena(player, enemy);
        arena.fight();
    }
}
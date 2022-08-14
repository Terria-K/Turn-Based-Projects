import { fight, newArena } from "./arena";
import { newEntity } from "./entity";

const player = newEntity("Player");
const enemy = newEntity("Enemy");

const arena = newArena(player, enemy);
let func = fight(arena);

setInterval(() => {
    func.next()
}, 1000)
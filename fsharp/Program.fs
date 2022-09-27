open TurnBasedFSharp
open System

let player = new Entity "Player"
let enemy = new Entity "Enemy"

printfn "Enter any key to start!"
ignore(Console.ReadLine())
let arena = new Arena(player, enemy)
arena.Fight()
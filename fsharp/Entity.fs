namespace TurnBasedFSharp
open System

type Entity(name: string) =
    member val Name = name with get
    member val Hp = 100 with set, get

    member _.DealDamageTo(entity: Entity, damage: int) =
        entity.Hp <- entity.Hp - damage
        Console.WriteLine("{0} Damages -> {1} with {2} dmg", name, entity.Name, damage)
        printfn "==============================="

    member _.AssignAttackDamage (max, random: Random) =
        random.Next() % max
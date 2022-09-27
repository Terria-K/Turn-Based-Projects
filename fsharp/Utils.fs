namespace TurnBasedFSharp

module Utils =
    let private random = new System.Random()

    let GenerateRandom x =
        random.Next() % x
    
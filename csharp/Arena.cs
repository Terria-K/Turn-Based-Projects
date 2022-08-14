namespace TurnBaseCombat;

public class Arena 
{
    enum States { IdleState, TurnAState, TurnBState, FinalState }

    private Entity constA;
    private Entity constB;
    private States gameState;

    public Arena(Entity constA, Entity constB)
    {
        this.constA = constA;
        this.constB = constB;
        this.gameState = States.IdleState;
    }

    public void Fight() 
    {
        var randomize = Utils.GenerateRandom(2);
        gameState = randomize switch 
        {
            1 => States.TurnBState,
            _ => States.TurnAState
        };

        var turn = 1;
        while (gameState != States.FinalState) 
        {
            var aDamage = constA.AssignAttackDamage(50);
            var bDamage = constA.AssignAttackDamage(50);

            switch (gameState) 
            {
                case States.TurnAState:
                    constA.DealDamageTo(constB, aDamage);
                    DisplayHealth();
                    Console.WriteLine("============Turn {0}===============", turn);
                    if (constB.Hp > 0)
                        Console.WriteLine("{0} Turn!", constB.Name);
                    gameState = States.TurnBState;
                    break;
                case States.TurnBState:
                    constB.DealDamageTo(constA, bDamage);
                    DisplayHealth();
                    Console.WriteLine("============Turn {0}===============", turn);
                    if (constA.Hp > 0)
                        Console.WriteLine("{0} Turn!", constB.Name);
                    gameState = States.TurnAState;
                    break;
            }

            if (constA.Hp < 1) 
            {
                gameState = States.FinalState;
                Console.WriteLine("{0} Wins!", constB.Name);
                continue;
            }
            if (constB.Hp < 1) 
            {
                gameState = States.FinalState;
                Console.WriteLine("{0} Wins!", constA.Name);
                continue;
            }

            turn++;
            Thread.Sleep(1000);
        }

        Prompt();
    }

    public void DisplayHealth() 
    {
        Console.WriteLine("{0} has {1} health", constA.Name, constA.Hp);
        Console.WriteLine("{0} has {1} health", constB.Name, constB.Hp);
    }

    public void Prompt() 
    {
        Console.WriteLine("Type 0 or above to continue the game, type -1 to exit!");
        if (!int.TryParse(Console.ReadLine(), out int res))
        {
            Console.WriteLine("Not a valid number!, exiting the program");
            return;
        }
        if (res > -1) 
        {
            constA.Hp = 100;
            constB.Hp = 100;
            Fight();
        }
    }
}

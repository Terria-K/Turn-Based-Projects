namespace TurnBaseCombat;

enum States { IdleState, TurnAState, TurnBState, FinalState }


public class Arena 
{
    private Random random = new Random();
    private Entity entityA;
    private Entity entityB;
    private States gameState;

    public Arena(Entity entityA, Entity entityB)
    {
        this.entityA = entityA;
        this.entityB = entityB;
        this.gameState = States.IdleState;
    }

    public void Fight() 
    {
        var randomize = random.Next() % 2;
        gameState = randomize switch 
        {
            1 => States.TurnBState,
            _ => States.TurnAState
        };

        var turn = 1;
        while (gameState != States.FinalState) 
        {
            var aDamage = entityA.AssignAttackDamage(50, random);
            var bDamage = entityB.AssignAttackDamage(50, random);

            switch (gameState) 
            {
                case States.TurnAState:
                    entityA.DealDamageTo(entityB, aDamage);
                    DisplayHealth();
                    Console.WriteLine("============Turn {0}===============", turn);
                    if (entityB.Hp > 0)
                        Console.WriteLine("{0} Turn!", entityB.Name);
                    gameState = States.TurnBState;
                    break;
                case States.TurnBState:
                    entityB.DealDamageTo(entityA, bDamage);
                    DisplayHealth();
                    Console.WriteLine("============Turn {0}===============", turn);
                    if (entityA.Hp > 0)
                        Console.WriteLine("{0} Turn!", entityA.Name);
                    gameState = States.TurnAState;
                    break;
            }

            if (entityA.Hp < 1) 
            {
                gameState = States.FinalState;
                Console.WriteLine("{0} Wins!", entityB.Name);
                continue;
            }
            if (entityB.Hp < 1) 
            {
                gameState = States.FinalState;
                Console.WriteLine("{0} Wins!", entityA.Name);
                continue;
            }

            turn++;
            Thread.Sleep(1000);	
        }

        Prompt();
    }

    public void DisplayHealth() 
    {
        Console.WriteLine("{0} has {1} HP", entityA.Name, entityA.Hp);
        Console.WriteLine("{0} has {1} HP", entityB.Name, entityB.Hp);
    }

    public void Prompt() 
    {
        Console.WriteLine("Type 0 or above to continue the game, type -1 to exit!");
        if (!int.TryParse(Console.ReadLine(), out int res))
        {
            return;
        }
        if (res > -1) 
        {
            entityA.Hp = 100;
            entityB.Hp = 100;
            Fight();
        }
    }
}

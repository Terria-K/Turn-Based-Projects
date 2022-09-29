namespace TurnBaseCombat;

public class Entity 
{
    public string Name { get; init; }
    public int Hp { get; set; }

    public Entity(string name)
    {
        this.Name = name;
        Hp = 100;
    }

    public void DealDamageTo(Entity entity, int damage) 
    {
        entity.Hp -= damage;
        Console.WriteLine("{0} Damages => {1} with {2} dmg", Name, entity.Name, damage);     
        Console.WriteLine("===============================");       
    }

    public int AssignAttackDamage(int max, Random random) 
    {
        return random.Next() % max;
    }
}

using TurnBaseCombat;

var player = new Entity("Player");
var enemy = new Entity("Enemy");

Console.WriteLine("Enter any key to start!");
Console.ReadLine();
var arena = new Arena(player, enemy);
arena.Fight();
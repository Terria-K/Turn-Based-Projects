<?php 
require 'entity.php';
require 'arena.php';

$player = new Entity("Player");
$enemy = new Entity("Enemy");
readline("Enter any key to start!\n");
$arena = new Arena($player, $enemy);
$arena->fight();
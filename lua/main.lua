math.randomseed(os.time())
local Entity = require("entity")
local Arena = require("arena")

local player = Entity.new("Player")
local enemy = Entity.new("Enemy")
print("Enter to start!")
_ = io.read("*l")
local arena = Arena:new(player, enemy)
arena:fight()

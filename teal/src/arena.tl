local Entity = require("src/entity")
local clock = os.clock

local function sleep(n: number)
    local t0 = clock()
    while clock() - t0 <= n do end
end


local enum States
    "idle"
    "turn_a"
    "turn_b"
    "final"
end

local record Arena
    entity_a: Entity
    entity_b: Entity
    state: States
    fight: function
    display_health: function
    prompt: function
end

function Arena:new(entity_a: Entity, entity_b: Entity): Arena
    self.entity_a = entity_a
    self.entity_b = entity_b
    self.state = "idle" 
    return self 
end

function Arena:fight()
    local randomize = math.random(2)
    self.state = randomize == 1 and "turn_a" or "turn_b"

    local turn = 1
    while self.state ~= "final" do
        local a_damage = self.entity_a:assign_attack_damage(50)
        local b_damage = self.entity_b:assign_attack_damage(50)
        print(string.format("============Turn %s===============", turn))
		if self.state == "turn_a" then
			self.entity_a:deal_damage_to(self.entity_b, a_damage)
            self:display_health()
			if self.entity_b.hp > 0 then
				print(string.format("%s Turn!\n", self.entity_b.name))
			end
			self.state = "turn_b" 
		elseif self.state == "turn_b" then
			self.entity_b:deal_damage_to(self.entity_a, b_damage)
			self:display_health()
			if self.entity_a.hp > 0 then
				print(string.format("%s Turn!\n", self.entity_a.name))
			end
			self.state = "turn_a" 
		end

		if self.entity_a.hp < 1 then
			self.state = "final"
			print(string.format("%s Wins!", self.entity_b.name))
		end
		if self.entity_b.hp < 1 then
			self.state = "final"
			print(string.format("%s Wins!", self.entity_a.name))
		end
		turn = turn + 1
		sleep(1)
    end
    self:prompt()
end

function Arena:display_health()
	print(string.format("%s has %d HP", self.entity_a.name, self.entity_a.hp))
	print(string.format("%s has %d HP", self.entity_b.name, self.entity_b.hp))
end

function Arena:prompt()
	print("Type 0 or above to continue the game, type -1 to exit")
	local inp = io.read("*n") as number
	if inp > -1 then
		self.entity_a.hp = 100
		self.entity_b.hp = 100
		self.fight(self)
	end
end



return Arena
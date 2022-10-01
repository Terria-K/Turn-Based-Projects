local Arena = {}
local clock = os.clock
local function sleep(n)
	local t0 = clock()
	while clock() - t0 <= n do
	end
end

local IDLE_STATE = 0
local TURN_A_STATE = 1
local TURN_B_STATE = 2
local FINAL_STATE = 3

function Arena:new(entity_a, entity_b)
	self.entity_a = entity_a
	self.entity_b = entity_b
	self.state = IDLE_STATE
	return Arena
end

function Arena:fight()
	local randomize = math.random(2)
	self.state = randomize == 1 and TURN_A_STATE or TURN_B_STATE

	local turn = 1
	while self.state ~= FINAL_STATE do
		local a_damage = self.entity_a:assign_attack_damage(50)
		local b_damage = self.entity_a:assign_attack_damage(50)

		if self.state == TURN_A_STATE then
			self.entity_a:deal_damage_to(self.entity_b, a_damage)
			self:display_health()
			if self.entity_b.hp > 0 then
				print(string.format("%s Turn!", self.entity_b.name))
			end
			self.state = TURN_B_STATE
		elseif self.state == TURN_B_STATE then
			self.entity_b:deal_damage_to(self.entity_a, b_damage)
			self:display_health()
			if self.entity_a.hp > 0 then
				print(string.format("%s Turn!", self.entity_a.name))
			end
			self.state = TURN_A_STATE
		end

		if self.entity_a.hp < 1 then
			self.state = FINAL_STATE
			print(string.format("%s Wins!", self.entity_b.name))
		end
		if self.entity_b.hp < 1 then
			self.state = FINAL_STATE
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
	local inp = io.read("*n")
	if inp > -1 then
		self.entity_a.hp = 100
		self.entity_b.hp = 100
		self.fight(self)
	end
end

return Arena

local new = function(name)
	Entity = { name = name, hp = 100 }
	function Entity:deal_damage_to(entity, damage)
		entity.hp = entity.hp - damage
		print(string.format("%s Damages => %s with %d dmg", self.name, entity.name, damage))
		print("===============================");
	end

	function Entity:assign_attack_damage(max)
		return math.random(max)
	end
	return Entity
end

return new

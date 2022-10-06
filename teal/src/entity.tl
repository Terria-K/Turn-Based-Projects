local record Entity
    name: string
    hp: integer
end

function Entity.new(name: string): Entity
    local self = setmetatable({} as Entity, { __index = Entity })
    self.name = name
    self.hp = 100
    return self
end

function Entity:deal_damage_to(entity: Entity, damage: integer)
    entity.hp = entity.hp - damage
    print(string.format("%s Damages => %s with %d dmg", self.name, entity.name, damage));
    print("===============================")
end

function Entity:assign_attack_damage(max: integer): integer
    return math.random(max)
end

return Entity
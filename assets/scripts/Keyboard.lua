local Key = require "Key"

local Keyboard = {}
Keyboard.__index = Keyboard

local function new()
  return setmetatable({keys={}}, Keyboard)
end

function Keyboard:setKeyDefinitions(newKeys)
	for i, v in ipairs(newKeys) do
		self.keys[v] = Key(v)
	end
end

function Keyboard:triggerKeyDown(keycode)
	self.keys[keycode]:setState(1)
end

function Keyboard:triggerKeyUp(keycode)
	self.keys[keycode]:setState(0)
end

function Keyboard:onKeyDown(keycode, closure)
	local listeners = self.keys[keycode].listeners
	table.insert(listeners, closure)
end

function Keyboard:onKeyUp(keycode, closure)
	
end

function Keyboard:isKeyDown(keycode)

end

function Keyboard.__tostring(a)
	local out = ""
	
	for k, v in pairs(a.keys) do
		out = out .. tostring(k) .. " : " .. tostring(v) .. "\n"
	end

	return out
end 

return setmetatable({new = new}, { __call = function(_, ...) return new(...) end })

local Key = {}
Key.__index = Key

local function new(keycode)
	local keyproto = {
		code = keycode,
		_state = 0,
		shift = false,
		control = false,
		alt = false,
		listeners = {}
	}
  return setmetatable(keyproto, Key)
end

function Key:notify()
	for i, v in ipairs(self.listeners) do
		self.listeners[i](self)
	end
end

function Key:setState(newstate)
	self._state = newstate
	self:notify()
end

function Key.__tostring(t)
	return "KEY::" .. t.code .. t._state
end

return setmetatable({new = new}, { __call = function(_, ...) return new(...) end })
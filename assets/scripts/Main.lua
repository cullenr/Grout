local Key = require "Key"
local Input = require "Keyboard"

grout = {}
-- grout.input = {}
grout.input = Input()


function add(lhs, rhs)
	return lhs + rhs
end
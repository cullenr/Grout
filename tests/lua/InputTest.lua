-- the first argument should be the module path
package.path = arg[1]

local Key = require "Key"
local Input = require "Keyboard"

callback = function(e)
  assert(e.code == "a")
end

local i = Input()

i:setKeyDefinitions({'a', 'b', 'c'})
i:onKeyDown('a', callback)
i:triggerKeyDown('a')
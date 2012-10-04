__INPUT = {
	__privates = {
		a = 5
	}
	__private_callback = function (k, ov, v)       
		v + k
	end
}
-- __INPUT_META = {
-- 	__index = function(self, k)
-- 		return rawget(self, "__privates")[k]
-- 	end,
-- 	__newindex = function(self, k, v)
-- 		local privates = rawget(self, "__privates")
-- 		local ov = privates[k]
-- 		privates[k] = v
-- 		rawget(self, "__private_callback")(self, k, ov, v)
-- 	end,
-- }
-- setmetatable(__INPUT, __INPUT_META)

function add ( x, y )
	return x + y
end
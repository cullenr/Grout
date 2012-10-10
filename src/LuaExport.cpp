#include "LuaExport";
#include "Scene.hpp"

void LuaExport::exportClasses()
{
	luabind::module(lua_State) [
		luabind::class_<Scene>("Scene")
			.def(luabind::constructor<>())
			.def("update", &Scene::update)
	];
}
GROUT
=====

Description
-----------

SDL based tile game engine with Lua scripting.

Build
-----

On the command line :

	mkdir build
	cd build
	cmake ..

or

	./compile.sh

Windows users should use the cmake gui or a mingw terminal.

Make sure you have OpenGL, SDL, SDL_image and Lua51 installed and that your cmake is up to date.

###Building Luaabind###
bjam --toolset=gcc link=static

note that the `link` param has no hyphen - this is something to do with bjam - whatever. 
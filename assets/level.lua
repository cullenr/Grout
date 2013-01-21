actor = Actor()

layer = Layer()
grout.ctx.scene:addRenderLayer("main", layer)

transform = Transform()
actor:addComponent("myTransform", transform)

texture = Texture("assets/tiles64x64.png")

rectangle = Rectangle(0, 0, 64, 64)



sprite = Sprite(texture, rectangle, transform)

layerChild = LayerChild(sprite)
layer:addChild(layerChild)

inputComponent = InputComponent()
inputComponent:setKeyDownCallback(function (val)
		for datum in val.data do
			print(datum)
		end

		-- print(val)
		transform.position.x = transform.position.x + 1
	end)

actor:addComponent("myInputComponent", inputComponent)

grout.ctx.scene:addActor(actor)

transform.position.x = 22
transform.position.y = 22


actor = Actor()

layer = Layer()
grout.ctx.scene:addRenderLayer("main", layer)

transform = Transform()
transform.position.x = 22
transform.position.y = 22
texture = Texture("assets/tiles64x64.png")
rectangle = Rectangle(0, 0, 64, 64)
sprite = Sprite(texture, rectangle, transform)
layerChild = LayerChild(sprite)
layer:addChild(layerChild)

actor:addComponent("myTransform", transform)

grout.ctx.scene:addActor(actor)
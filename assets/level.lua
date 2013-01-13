actor = Actor()

transform = Transform()
texture = Texture("assets/tiles64x64.png")
rectangle = Rectangle(0, 0, 64, 64)
sprite = Sprite(texture, rectangle)

actor:addComponent("myTransform", transform)
actor:addComponent("mySprite", sprite)

grout.ctx.scene:addActor(actor)
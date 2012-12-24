actor = Actor()

transform = Transform()
renderer = Renderer()

actor:addComponent("myTransform", transform)
actor:addComponent("myRenderer", renderer)

grout.ctx.scene:addActor(actor)
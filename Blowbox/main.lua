Game.Update = function (dt)
	Game.t = Game.t or 0

	Game.t = Game.t + 1

	quaderino:setPosition2D(Game.t / 100, 0)

	if (Game.t == 300) then
		rendertarget:setQueue(renderqueue)
	end
end

rendertarget = RenderTarget.new("loool")
renderqueue = RenderQueue.new(rendertarget)

anotherqueue = RenderQueue.new(rendertarget)

quaderino = Quad.new(renderqueue)
quad2 = Quad.new(anotherqueue)

quaderino:setScale2D(50, 50)
quad2:setScale2D(75, 75)
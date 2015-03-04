#include "game.h"

#include "../blowbox/win32/window.h"
#include "../blowbox/input/mouse.h"
#include "../blowbox/input/keyboard.h"
#include "../blowbox/d3d11/d3d11_render_device.h"
#include "../blowbox/d3d11/d3d11_render_target.h"
#include "../blowbox/d3d11/d3d11_render_queue.h"
#include "../blowbox/elements/quad.h"
#include "../blowbox/lua/lua_state.h"
#include "../blowbox/lua/lua_register.h"

namespace blowbox
{
	//------------------------------------------------------------------------------------------------------
	Game::Game()
	{
		LuaState::Instance();

		window_ = new Window();
		mouse_ = Mouse::Instance();
		keyboard_ = Keyboard::Instance();
		renderDevice_ = D3D11RenderDevice::Instance();
	}

	//------------------------------------------------------------------------------------------------------
	Game::~Game()
	{

	}

	//------------------------------------------------------------------------------------------------------
	Game* Game::Instance()
	{
		static SharedPtr<Game> ptr(new Game());
		return ptr.get();
	}

	//------------------------------------------------------------------------------------------------------
	void Game::Run()
	{
		Window* window = window_.get();
		
		window->Create(std::string("blowbox"), 640, 480);
		window->SetStarted(true);

		renderDevice_->Initialize(window);

		quad_ = new Quad();
		renderDevice_->GetRenderTarget("hurdur")->GetQueue()->Add(quad_.get());

		quad_->SetPosition(0.0f, 0.0f, 0.0f);
		quad_->SetScale(50, 50, 1);
		quad_->SetShader("shaders/base.fx");

		quad2_ = new Quad();
		renderDevice_->GetRenderTarget("hurdur")->GetQueue()->Add(quad2_.get());

		quad2_->SetPosition(25.0f, 0.0f, 0.0f);
		quad2_->SetScale(50, 50, 1);
		quad2_->SetShader("shaders/base.fx");

		while (window->GetStarted())
		{
			Update();
			Draw();
		}
	}

	//------------------------------------------------------------------------------------------------------
	void Game::Update()
	{
		window_.get()->ProcessMessages();
		mouse_->Update();
		keyboard_->Update();
	}
	
	//------------------------------------------------------------------------------------------------------
	void Game::Draw()
	{
		renderDevice_->Draw();
	}
}
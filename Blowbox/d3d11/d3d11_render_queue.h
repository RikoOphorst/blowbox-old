#pragma once

#include <vector>

#include "../../blowbox/d3d11/d3d11.h"
#include "../../blowbox/lua/lua_class.h"

namespace blowbox
{
	class D3D11RenderElement;
	
	/**
	* @class blowbox::D3D11RenderQueue
	* @brief Handles render queues of render elements
	*/
	class D3D11RenderQueue : public LuaClass
	{
	public:
		/**
		* @brief Default D3D11RenderQueue constructor
		*/
		D3D11RenderQueue();

		/**
		* @brief Lua D3D11RenderQueue constructor
		* @param[in] L (lua_State*) the lua state
		*/
		D3D11RenderQueue(lua_State* L);

		/**
		* @brief Default D3D11RenderQueue destructor
		*/
		~D3D11RenderQueue();

		/**
		* @brief Draws all the elements
		* @param[in] context (ID3D11DeviceContext*) the device context
		*/
		void Draw(ID3D11DeviceContext* context);

		/**
		* @brief Adds an element to the queue
		*/
		void Add(D3D11RenderElement* element);

		/**
		* @brief Draws a specific element
		* @param[in] context (ID3D11DeviceContext*) the device context
		* @param[in] element (D3D11RenderElement*) the element to be rendered
		*/
		void DrawElement(ID3D11DeviceContext* context, D3D11RenderElement* element);

		/**
		* @brief Registers this object's lua functions
		* @param[in] L (lua_State*) the lua state
		*/
		static void LuaRegisterFunctions(lua_State* L);

		/**
		* @brief Adds an element to this queue
		* @param[in] L (lua_State*) the lua state
		*/
		static int LuaAdd(lua_State* L);

		CLASSNAME("RenderQueue");
	private:
		std::vector<D3D11RenderElement*> queue_;
	};
}
#pragma once

#include "entity.hpp"
#include "loaderParams.hpp"

class MenuButton : public Entity
{

public:
	MenuButton(const LoaderParams* pParams, void (*callback)());

	virtual void draw();
	virtual void update();
	virtual void clean();

	// virtual void load(const LoaderParams *pParams);

	// void setCallback(void (*callback)()) { m_callback = callback; }
	// int getCallbackID() { return m_callbackID; }

private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	bool m_bReleased;

	void (*m_callback)();
};
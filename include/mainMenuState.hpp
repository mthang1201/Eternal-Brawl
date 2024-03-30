#pragma once
#include <vector>

#include "menuState.hpp"
#include "entity.hpp"

class MainMenuState :public MenuState
{
	static const std::string s_menuID;

	//vector to store menu items
	std::vector<Entity*> m_entities;

	//call back functions for menu items
	static void s_menuToPlay();
	static void s_exitFromMenu();

	virtual void setCallbacks(const std::vector<Callback> &Callbacks);
	
public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }
};

#endif //defined(__MenuState__)
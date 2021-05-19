#pragma once

#include <vector>
#include <string>


struct Listener
{
	char bindChar;
	int bindInt;
	std::string name;
	bool active;
};

class ListenerManager
{
public:
	ListenerManager();
	~ListenerManager();
	bool CheckListener(Listener ev);
	bool CheckTrigger(Listener ev);
	Listener PrevEvent();
	Listener CurrentEvent();
	void AddListener(Listener ev);
private:
	std::vector<Listener> listeners;
	std::vector<Listener> eventList;
	Listener none;
};
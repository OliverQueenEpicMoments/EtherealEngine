#pragma once
#include "Event.h"
#include <map>
#include <list>

namespace Ethrl {
	class GameObject;
	class EventManager {
	public:
		struct Observer {
			GameObject* Reciever;
			Event::FunctionPtr Function;
		};

	public:
		void Initialize();
		void Shutdown();
		void Update();

		void Subscribe(const std::string& name, Event::FunctionPtr function, GameObject* reciever = nullptr);
		void Unsubscribe(const std::string& name, GameObject* reciever);
		void Notify(const Event& event_);

	private:
		std::map<std::string, std::list<Observer>> m_Events;
	};
}
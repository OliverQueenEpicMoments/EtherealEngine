#include "EventManager.h"

void Ethrl::EventManager::Initialize() {

}

void Ethrl::EventManager::Shutdown() {

}

void Ethrl::EventManager::Update() {

}

void Ethrl::EventManager::Subscribe(const std::string& name, Event::FunctionPtr function, GameObject* reciever) {
	Observer observer;
	observer.Reciever = reciever;
	observer.Function = function;

	m_Events[name].push_back(observer);
}

void Ethrl::EventManager::Unsubscribe(std::string& name, GameObject* reciever) {

}

void Ethrl::EventManager::Notify(const Event& event_) {
	auto observers = m_Events[event_.Name];
	for (auto& observer : observers) {
		if (event_.Reciever == nullptr || event_.Reciever == observer.Reciever) {
			observer.Function(event_);
		}
	}
}
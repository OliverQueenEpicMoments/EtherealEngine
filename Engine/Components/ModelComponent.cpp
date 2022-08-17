#include "ModelComponent.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"
#include "FrameWork/Actor.h"
#include "Engine.h"

void Ethrl::ModelComponent::Update() {

}

void Ethrl::ModelComponent::Draw(Renderer& renderer) {
	m_Model->Draw(renderer, m_Owner->m_Transform);
}

bool Ethrl::ModelComponent::Write(const rapidjson::Value& value) const {
	return true;
}

bool Ethrl::ModelComponent::Read(const rapidjson::Value& value) {
	std::string model_name;
	READ_DATA(value, model_name);

	m_Model = g_Resources.Get<Model>(model_name);

	return true;
}

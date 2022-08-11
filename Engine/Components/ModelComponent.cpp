#include "ModelComponent.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"
#include "FrameWork/Actor.h"

void Ethrl::ModelComponent::Update() {

}

void Ethrl::ModelComponent::Draw(Renderer& renderer) {
	//renderer.Draw(m_Model, m_Owner->m_Transform);
	m_Model->Draw(renderer, m_Owner->m_Transform);
}

#include "SpriteComponent.h"
#include "Renderer/Renderer.h"
#include "FrameWork/Actor.h"

void Ethrl::SpriteComponent::Update() {

}

void Ethrl::SpriteComponent::Draw(Renderer& renderer) {
	renderer.Draw(m_Texture, m_Owner->m_Transform);
}

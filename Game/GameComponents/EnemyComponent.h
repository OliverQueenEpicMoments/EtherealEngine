#pragma once
#include "Components/CharacterComponent.h"

class EnemyComponent : public Ethrl::CharacterComponent {
public:
	CLASS_DECLARATION(EnemyComponent)

	virtual void Initialize() override;
	virtual void Update() override;

	virtual void OnCollisionEnter(Ethrl::Actor* other) override;
	virtual void OnCollisionExit(Ethrl::Actor* other) override;

	virtual void OnNotify(const Ethrl::Event& event) override;

	virtual bool Write(const rapidjson::Value& value) const override;
	virtual bool Read(const rapidjson::Value& value) override;

protected:
};
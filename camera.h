#pragma once

#include	<SimpleMath.h>

#include "GameObject.h"

class Camera : public GameObject {
private:

	DirectX::SimpleMath::Vector3	m_Position{};
	DirectX::SimpleMath::Vector3	m_Target{};
	DirectX::SimpleMath::Matrix		m_ViewMatrix{};

public:
	virtual void Init(void) override;
	virtual void Uninit(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;

};
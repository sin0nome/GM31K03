#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "camera.h"

using namespace DirectX::SimpleMath;

void Camera::Init() {
	m_Position = Vector3(0.0f, 10.0f, -50.0f);
	m_Target = Vector3(0.0f, 0.0f, 0.0f);
}

void Camera::Uninit() {
}



void Camera::Update() {

}

void Camera::Draw() {
	// �r���[�ϊ����쐬
	Vector3 up = Vector3(0.0f, 1.0f, 0.0f);
	m_ViewMatrix = DirectX::XMMatrixLookAtLH(m_Position, m_Target, up);										// ����n�ɂ����@20230511 by suzuki.tomoki

	// DIRECTXTK�̃��\�b�h�͉E��n�@20230511 by suzuki.tomoki
	// �E��n�ɂ���ƂR�p�`���_�������v���ɂȂ�̂ŕ`�悳��Ȃ��Ȃ�̂Œ���
	// ���̃R�[�h�͊m�F�e�X�g�̂��߂Ɏc��
	//	m_ViewMatrix = m_ViewMatrix.CreateLookAt(m_Position, m_Target, up);					

	Renderer::SetViewMatrix(&m_ViewMatrix);

	//�v���W�F�N�V�����s��̐���
	constexpr float fieldOfView = DirectX::XMConvertToRadians(45.0f);    // ����p

	float aspectRatio = static_cast<float>(SCREEN_WIDTH) / static_cast<float>(SCREEN_HEIGHT);	// �A�X�y�N�g��	
	float nearPlane = 1.0f;       // �j�A�N���b�v
	float farPlane = 1000.0f;      // �t�@�[�N���b�v

	//�v���W�F�N�V�����s��̐���
	Matrix projectionMatrix;
	projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(fieldOfView, aspectRatio, nearPlane, farPlane);	// ����n�ɂ����@20230511 by suzuki.tomoki

	// DIRECTXTK�̃��\�b�h�͉E��n�@20230511 by suzuki.tomoki
	// �E��n�ɂ���ƂR�p�`���_�������v���ɂȂ�̂ŕ`�悳��Ȃ��Ȃ�̂Œ���
	// ���̃R�[�h�͊m�F�e�X�g�̂��߂Ɏc��
//	projectionMatrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(fieldOfView, aspectRatio, nearPlane, farPlane);

	Renderer::SetProjectionMatrix(&projectionMatrix);
}
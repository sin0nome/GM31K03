#include	"polygon2D.h"
#include	"renderer.h"
#include	"manager.h"
#include	"field.h"
#include	"camera.h"


// �O���[�o���ϐ�
decltype(Manager::object) Manager::object;

void Manager::Init(Application* ap) {
	// �^�C�}�𑜓x���P�~���b�ɂ���
	timeBeginPeriod(1);

	// �����_���[��������
	Renderer::Init(ap);

	// �|���S��������
	// �J����������
	// �t�B�[���h������
	Manager::object.emplace_back(std::make_shared<Polygon2D>());
	Manager::object.emplace_back(std::make_shared<Camera>());
	Manager::object.emplace_back(std::make_shared<Field>());
	for(const auto& obj : Manager::object) {
		obj->Init();
	}

}

void Manager::Uninit() {
	// �|���S���폜
	// �J�����I������
	// �t�B�[���h�I������(�J�����Ԋ֌W����Ȃ�v�C��)
	for(const auto& obj : Manager::object) {
		obj->Uninit();
	}

	// �����_���[�I������
	Renderer::Uninit();

	// �^�C�}�𑜓x�����ɖ߂�
	timeEndPeriod(1);
}

void Manager::Update(uint64_t d) {
	for(const auto& obj : Manager::object) {
		obj->Update();
	}
}

void Manager::Draw(uint64_t d) {
	Renderer::Begin();
	for(const auto& obj : Manager::object) {
		obj->Draw();
	}
	Renderer::End();
}

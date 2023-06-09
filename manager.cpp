#include	"polygon2D.h"
#include	"renderer.h"
#include	"manager.h"
#include	"field.h"
#include	"camera.h"


// グローバル変数
decltype(Manager::object) Manager::object;

void Manager::Init(Application* ap) {
	// タイマ解像度を１ミリ秒にする
	timeBeginPeriod(1);

	// レンダラーを初期化
	Renderer::Init(ap);

	// ポリゴン初期化
	// カメラ初期化
	// フィールド初期化
	Manager::object.emplace_back(std::make_shared<Polygon2D>());
	Manager::object.emplace_back(std::make_shared<Camera>());
	Manager::object.emplace_back(std::make_shared<Field>());
	for(const auto& obj : Manager::object) {
		obj->Init();
	}

}

void Manager::Uninit() {
	// ポリゴン削除
	// カメラ終了処理
	// フィールド終了処理(開放順番関係あるなら要修正)
	for(const auto& obj : Manager::object) {
		obj->Uninit();
	}

	// レンダラー終了処理
	Renderer::Uninit();

	// タイマ解像度を元に戻す
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

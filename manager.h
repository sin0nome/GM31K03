#pragma once
#include	<cinttypes>
#include <vector>
#include <memory>

// ‘O•ûQÆ
class Application;
class GameObject;

class Manager {
private:
	static std::vector<std::shared_ptr<GameObject>> object;
public:
	static void Init(Application* ap);
	static void Uninit();
	static void Update(uint64_t d);
	static void Draw(uint64_t d);
};
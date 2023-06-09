#pragma once


class GameObject {
private:



protected:



public:

	explicit GameObject(void);
	explicit GameObject(const GameObject& object);
	virtual ~GameObject(void) noexcept;

	virtual void Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

};


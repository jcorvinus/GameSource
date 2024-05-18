#include "Updateable.h"
#include "Transform.h"
#include <memory>
#include <vector>

#pragma once
class Entity
{
public:
	Entity();
	//~Entity();

	void Update();
	void Draw();

	template <typename T>
	std::shared_ptr<T> AddUpdateable(T* component);
	template <typename T>
	void RemoveUpdateable(std::shared_ptr<T> updateable);

protected:
	virtual void Start();
	virtual void PreUpdate();
	virtual void PreDraw();

	std::shared_ptr<Transform> transform;

private:
	std::vector<std::shared_ptr<Updateable>> m_Updateables;
};
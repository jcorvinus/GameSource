#include "Updateable.h"
#include "Transform.h"
#include <memory>
#include <vector>

#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	void Update();
	void Draw();

protected:
	virtual void Start();
	virtual void PreUpdate();
	virtual void PreDraw();
	std::shared_ptr<Transform> transform;
	std::shared_ptr<Updateable> AddUpdateable(Updateable* component);
	void RemoveUpdateable(std::shared_ptr<Updateable> updateable);

private:
	std::vector<std::shared_ptr<Updateable>> m_Updateables;
};
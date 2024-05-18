#include "Entity.h"
#include <memory>

void Entity::Update()
{
	PreUpdate();

	// run through all of our updatables and execute
	for (const auto& updatable : m_Updateables)
	{
		updatable->Update();
	}
}

void Entity::Draw()
{
	PreDraw();

	// todo: update our drawables
}

std::shared_ptr<Updateable> AddUpdateable(Updateable* component)
{
	std::shared_ptr<Updateable> sharedUpdatable = std::make_shared<Updateable>(component);

	return sharedUpdatable;
}

void Entity::RemoveUpdateable(std::shared_ptr<Updateable> updateable)
{
	auto it = std::find(m_Updateables.begin(), m_Updateables.end(), updateable);

	if (it != m_Updateables.end())
	{
		m_Updateables.erase(it);
	}
}

Entity::Entity()
{
	Transform newTransform = Transform();
	transform = AddUpdateable(&newTransform);
}

Entity::~Entity()
{
	// clear all of our updateables
}
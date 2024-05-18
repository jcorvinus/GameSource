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

template<typename T>
std::shared_ptr<T> Entity::AddUpdateable(T* component)
{
	std::shared_ptr<T> sharedUpdatable = std::make_shared<T>(component);

	m_Updateables.push_back(sharedUpdatable);

	return sharedUpdatable;
}

template <typename T>
void Entity::RemoveUpdateable(std::shared_ptr<T> updateable)
{
	auto it = std::find(m_Updateables.begin(), m_Updateables.end(), updateable);

	if (it != m_Updateables.end())
	{
		m_Updateables.erase(it);
	}
}

std::shared_ptr<Transform> Entity::GetTransform()
{
	return transform;
}

void Entity::Start() {};
void Entity::PreUpdate() {};
void Entity::PreDraw() {};

Entity::Entity()
{
	transform = std::make_shared<Transform>();
}
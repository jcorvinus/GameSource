#pragma once
class Entity
{
public:
	void Update();
	void Draw();

protected:
	virtual void Start();
	virtual void PreUpdate();
	virtual void PreDraw();

private:

	// do we add our vectors for component lists here?
};
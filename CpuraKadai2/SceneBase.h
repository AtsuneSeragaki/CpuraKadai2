#pragma once

class SceneBase
{
public:
	virtual void Update() = 0;
	virtual void Draw() const = 0;
};


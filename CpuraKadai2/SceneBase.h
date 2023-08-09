#pragma once

class SceneBase
{
public:
	~SceneBase() {};
	virtual void Update() = 0;         // XVˆ—
	virtual void Draw() const = 0;     // •`‰æˆ—
	virtual SceneBase* Change() = 0;   // ‘JˆÚæ‚Ìw’è
};


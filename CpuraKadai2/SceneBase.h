#pragma once

class SceneBase
{
public:
	~SceneBase() {};
	virtual void Update() = 0;         // �X�V����
	virtual void Draw() const = 0;     // �`�揈��
	virtual SceneBase* Change() = 0;   // �J�ڐ�̎w��
};


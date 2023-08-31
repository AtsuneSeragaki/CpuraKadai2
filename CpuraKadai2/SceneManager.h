#pragma once
#include "SceneBase.h"

class SceneManager : public SceneBase
{
private:
	SceneBase* now_scene;    // ���݂̃V�[��
	SceneBase* next_scene;   // ���̃V�[��

public:
	SceneManager();                    // �R���X�g���N�^
	SceneManager(SceneBase* scene);    // �����t���R���X�g���N�^(�J�ڐ���w��)
	~SceneManager();                   // �f�X�g���N�^

	void Update() override;            // �X�V����
	void Draw() const override;        // �`�揈��
	SceneBase* Change() override;      // �J�ڐ�̎w��
};


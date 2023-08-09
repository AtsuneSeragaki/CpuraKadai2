#include "SceneManager.h"
#include "DxLib.h"

// �R���X�g���N�^
SceneManager::SceneManager()
{
	now_scene = nullptr;
	next_scene = now_scene;
}

// �����t���R���X�g���N�^
// �����F�ŏ��̃V�[�����
SceneManager::SceneManager(SceneBase* scene)
{
	now_scene = scene;
	next_scene = now_scene;
}

// �f�X�g���N�^
SceneManager::~SceneManager()
{

}

// �X�V����
void SceneManager::Update()
{
	if (now_scene != nullptr)
	{
		now_scene->Update();
	}
}

// �`�揈��
void SceneManager::Draw() const
{

	// �V�[����ʂ̕`��
	if (now_scene != nullptr)
	{
		now_scene->Draw();
	}

}

// �J�ڐ�̎w�菈��
SceneBase* SceneManager::Change()
{
	// �J�ڐ���󂯎��
	next_scene = now_scene->Change();

	// �J�ڐ悪���݂̃V�[���ƈ���Ă�����ύX����
	if (next_scene != now_scene)
	{
		delete now_scene;
		now_scene = next_scene;
	}

	// �J�ڐ��ԋp
	return next_scene;
}

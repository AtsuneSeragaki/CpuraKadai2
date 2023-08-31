#pragma once
#include "SceneBase.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class GameMainScene : public SceneBase
{
private:
	int stageImg;                // �X�e�[�W�̔w�i�摜
	int stageImgX,stageImgY;     // �X�e�[�W�̔w�i�摜�`��ʒu
	int life;                    // �v���C���[�̎c�@
	const int enemyMax = 20;     // �G�̍ő吔 
	const int bulletMax = 100;   // �e�̍ő吔
	int okFlg;                   // �{�^�����������������e�𐶐�����p�t���O
	int okFlg2;                  // �{�^�����������������G�𐶐�����p�t���O
	int Fcnt;                    // �t���[���J�E���g�p�ϐ�
	Bullet* bullet[100];         // �e�̃|�C���^�z��
	Player player;               // �v���C���[�̕ϐ�
	Enemy* enemy[20];            // �G�̃|�C���^�z��

public:
	GameMainScene();   // �R���X�g���N�^
	~GameMainScene();  // �f�X�g���N�^

	int HitCheck();     // �e�A�v���C���[�A�G�̓����蔻��̃`�F�b�N���s��
	void BackScrool();  // �w�i�摜�̃X�N���[������

	void Update() override;         // �X�V����
	void Draw() const override;     // �`�揈��
	SceneBase* Change() override;   // �J�ڐ�̎w��
	void SpawnBullet();             // �e�̔z��ɐV�����f�[�^���쐬����

};


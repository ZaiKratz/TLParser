#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Game.h"

//begin namespace block
namespace COMMON
{
class MessageMediaGame : public TLBaseObject
{
public:
	MessageMediaGame();
	MessageMediaGame(COMMON::Game* game);

	~MessageMediaGame();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::Game*  Getgame() const
	{
		 return this->game;
	}

private:
	COMMON::Game* game;
};
} //end namespace block

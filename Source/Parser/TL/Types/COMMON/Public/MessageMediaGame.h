#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Common/Public/Game.h"
#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaGame : public PRIVATE::MessageMedia
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

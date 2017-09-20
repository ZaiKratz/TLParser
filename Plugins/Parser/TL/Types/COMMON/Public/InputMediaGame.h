#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Private/InputGame.h"
#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaGame : public PRIVATE::InputMedia
{
public:
	InputMediaGame();
	InputMediaGame(PRIVATE::InputGame* id);

	~InputMediaGame();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PRIVATE::InputGame* id;
};
} //end namespace block

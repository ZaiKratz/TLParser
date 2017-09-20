#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/KeyboardButton.h"

//begin namespace block
namespace COMMON
{
class KeyboardButtonGame : public TLBaseObject
{
public:
	KeyboardButtonGame();
	KeyboardButtonGame(FString text);

	~KeyboardButtonGame();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString text;
};
} //end namespace block

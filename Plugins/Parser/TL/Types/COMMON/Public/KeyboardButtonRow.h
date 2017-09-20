#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/KeyboardButton.h"

//begin namespace block
namespace COMMON
{
class KeyboardButtonRow : public TLBaseObject
{
public:
	KeyboardButtonRow();
	KeyboardButtonRow(TArray<COMMON::KeyboardButton*> buttons);

	~KeyboardButtonRow();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::KeyboardButton*> buttons;
};
} //end namespace block

#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/KeyboardButton.h"

//begin namespace block
namespace COMMON
{
class KeyboardButtonCallback : public TLBaseObject
{
public:
	KeyboardButtonCallback();
	KeyboardButtonCallback(FString text, TArray<uint8> data);

	~KeyboardButtonCallback();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString text;
	 TArray<uint8> data;
};
} //end namespace block

#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaContact : public PRIVATE::InputMedia
{
public:
	InputMediaContact();
	InputMediaContact(FString phone_number, FString first_name, FString last_name);

	~InputMediaContact();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString phone_number;
	 FString first_name;
	 FString last_name;
};
} //end namespace block

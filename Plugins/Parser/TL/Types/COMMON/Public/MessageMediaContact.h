#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaContact : public PRIVATE::MessageMedia
{
public:
	MessageMediaContact();
	MessageMediaContact(FString phone_number, FString first_name, FString last_name, int32 user_id);

	~MessageMediaContact();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString phone_number;
	 FString first_name;
	 FString last_name;
	 int32 user_id;
};
} //end namespace block

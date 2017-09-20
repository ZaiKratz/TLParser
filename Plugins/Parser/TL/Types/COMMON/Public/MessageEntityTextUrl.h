#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageEntity.h"

#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class MessageEntityTextUrl : public PRIVATE::MessageEntity
{
public:
	MessageEntityTextUrl();
	MessageEntityTextUrl(int32 offset, int32 length, FString url);

	~MessageEntityTextUrl();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 offset;
	 int32 length;
	 FString url;
};
} //end namespace block

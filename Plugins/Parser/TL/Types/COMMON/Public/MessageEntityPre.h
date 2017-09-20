#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageEntity.h"

#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class MessageEntityPre : public PRIVATE::MessageEntity
{
public:
	MessageEntityPre();
	MessageEntityPre(int32 offset, int32 length, FString language);

	~MessageEntityPre();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 offset;
	 int32 length;
	 FString language;
};
} //end namespace block

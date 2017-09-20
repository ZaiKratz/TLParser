#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageEntity.h"

#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class MessageEntityEmail : public PRIVATE::MessageEntity
{
public:
	MessageEntityEmail();
	MessageEntityEmail(int32 offset, int32 length);

	~MessageEntityEmail();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 offset;
	 int32 length;
};
} //end namespace block

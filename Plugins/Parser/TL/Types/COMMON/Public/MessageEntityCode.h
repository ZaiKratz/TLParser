#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageEntity.h"

#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class MessageEntityCode : public PRIVATE::MessageEntity
{
public:
	MessageEntityCode();
	MessageEntityCode(int32 offset, int32 length);

	~MessageEntityCode();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 offset;
	 int32 length;
};
} //end namespace block

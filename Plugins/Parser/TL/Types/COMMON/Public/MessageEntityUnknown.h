#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageEntity.h"

#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class MessageEntityUnknown : public PRIVATE::MessageEntity
{
public:
	MessageEntityUnknown();
	MessageEntityUnknown(int32 offset, int32 length);

	~MessageEntityUnknown();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 offset;
	 int32 length;
};
} //end namespace block

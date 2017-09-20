#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageEntity.h"

#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class MessageEntityHashtag : public PRIVATE::MessageEntity
{
public:
	MessageEntityHashtag();
	MessageEntityHashtag(int32 offset, int32 length);

	~MessageEntityHashtag();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 offset;
	 int32 length;
};
} //end namespace block

#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageEntity.h"

#include "../../../Types/Private/MessageEntity.h"

//begin namespace block
namespace COMMON
{
class MessageEntityItalic : public PRIVATE::MessageEntity
{
public:
	MessageEntityItalic();
	MessageEntityItalic(int32 offset, int32 length);

	~MessageEntityItalic();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 offset;
	 int32 length;
};
} //end namespace block

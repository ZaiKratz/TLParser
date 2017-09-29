#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaEmpty : public PRIVATE::MessageMedia
{
public:
	MessageMediaEmpty();
	~MessageMediaEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
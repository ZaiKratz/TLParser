#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaUnsupported : public PRIVATE::MessageMedia
{
public:
	MessageMediaUnsupported();
	~MessageMediaUnsupported();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block

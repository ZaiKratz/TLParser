#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Common/Public/Document.h"
#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaDocument : public PRIVATE::MessageMedia
{
public:
	MessageMediaDocument();
	MessageMediaDocument(COMMON::Document* document, FString caption, int32 ttl_seconds);

	~MessageMediaDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::Document* document;
	 FString caption;
	 int32 ttl_seconds;
};
} //end namespace block

#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Common/Public/WebPage.h"
#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaWebPage : public PRIVATE::MessageMedia
{
public:
	MessageMediaWebPage();
	MessageMediaWebPage(COMMON::WebPage* webpage);

	~MessageMediaWebPage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::WebPage*  Getwebpage() const
	{
		 return this->webpage;
	}

private:
	COMMON::WebPage* webpage;
};
} //end namespace block

#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace MESSAGES
{
class GetWebPagePreview : public PRIVATE::MessageMedia
{
public:
	GetWebPagePreview();
	GetWebPagePreview(FString message);

	~GetWebPagePreview();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getmessage() const
	{
		 return this->message;
	}

	PRIVATE::MessageMedia* GetResult() const
	{
		 return this->result;
	}

private:
	FString message;
	PRIVATE::MessageMedia* result;
};
} //end namespace block

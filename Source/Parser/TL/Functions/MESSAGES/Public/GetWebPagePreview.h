#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class GetWebPagePreview : public TLBaseObject
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

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	FString message;
	TLBaseObject* result;
};
} //end namespace block

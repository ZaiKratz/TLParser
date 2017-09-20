#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/WebPage.h"

//begin namespace block
namespace MESSAGES
{
class GetWebPage : public TLBaseObject
{
public:
	GetWebPage();
	GetWebPage(FString url, int32 hash);

	~GetWebPage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString url;
	 int32 hash;
	COMMON::WebPage* result;
};
} //end namespace block

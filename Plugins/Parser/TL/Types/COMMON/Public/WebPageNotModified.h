#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/WebPage.h"

//begin namespace block
namespace COMMON
{
class WebPageNotModified : public TLBaseObject
{
public:
	WebPageNotModified();
	~WebPageNotModified();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block

#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/WebPage.h"

//begin namespace block
namespace COMMON
{
class WebPageEmpty : public TLBaseObject
{
public:
	WebPageEmpty();
	WebPageEmpty(unsigned long long id);

	~WebPageEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
};
} //end namespace block

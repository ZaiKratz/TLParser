#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Help/Public/Support.h"

//begin namespace block
namespace HELP
{
class GetSupport : public TLBaseObject
{
public:
	GetSupport();
	~GetSupport();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	HELP::Support* result;
};
} //end namespace block

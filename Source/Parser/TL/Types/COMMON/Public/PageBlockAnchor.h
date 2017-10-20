#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockAnchor : public TLBaseObject
{
public:
	PageBlockAnchor();
	PageBlockAnchor(FString name);

	~PageBlockAnchor();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getname() const
	{
		 return this->name;
	}

private:
	FString name;
};
} //end namespace block

#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockAnchor : public PRIVATE::PageBlock
{
public:
	PageBlockAnchor();
	PageBlockAnchor(FString name);

	~PageBlockAnchor();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString name;
};
} //end namespace block

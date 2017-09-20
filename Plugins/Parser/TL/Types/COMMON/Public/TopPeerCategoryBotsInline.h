#pragma once
#include "Engine.h"
#include "../../../Types/Private/TopPeerCategory.h"

#include "../../../Types/Private/TopPeerCategory.h"

//begin namespace block
namespace COMMON
{
class TopPeerCategoryBotsInline : public PRIVATE::TopPeerCategory
{
public:
	TopPeerCategoryBotsInline();
	~TopPeerCategoryBotsInline();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block

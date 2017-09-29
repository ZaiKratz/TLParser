#pragma once
#include "Engine.h"
#include "../../../Types/Private/TopPeerCategory.h"

#include "../../../Types/Private/TopPeerCategory.h"

//begin namespace block
namespace COMMON
{
class TopPeerCategoryChannels : public PRIVATE::TopPeerCategory
{
public:
	TopPeerCategoryChannels();
	~TopPeerCategoryChannels();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block

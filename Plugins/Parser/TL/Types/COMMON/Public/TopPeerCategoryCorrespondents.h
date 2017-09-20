#pragma once
#include "Engine.h"
#include "../../../Types/Private/TopPeerCategory.h"

#include "../../../Types/Private/TopPeerCategory.h"

//begin namespace block
namespace COMMON
{
class TopPeerCategoryCorrespondents : public PRIVATE::TopPeerCategory
{
public:
	TopPeerCategoryCorrespondents();
	~TopPeerCategoryCorrespondents();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block

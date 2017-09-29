#pragma once
#include "Engine.h"
#include "../../../Types/Private/PageBlock.h"

#include "../../../Types/Private/PageBlock.h"
#include "../../../Types/Private/PageBlock.h"

//begin namespace block
namespace COMMON
{
class PageBlockCover : public PRIVATE::PageBlock
{
public:
	PageBlockCover();
	PageBlockCover(PRIVATE::PageBlock* cover);

	~PageBlockCover();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::PageBlock*  Getcover() const
	{
		 return this->cover;
	}

private:
	PRIVATE::PageBlock* cover;
};
} //end namespace block

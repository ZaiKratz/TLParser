#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PageBlockCover : public TLBaseObject
{
public:
	PageBlockCover();
	PageBlockCover(TLBaseObject* cover);

	~PageBlockCover();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getcover() const
	{
		 return this->cover;
	}

private:
	TLBaseObject* cover;
};
} //end namespace block

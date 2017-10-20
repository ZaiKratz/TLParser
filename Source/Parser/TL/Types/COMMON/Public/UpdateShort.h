#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace COMMON
{
class UpdateShort : public TLBaseObject
{
public:
	UpdateShort();
	UpdateShort(TLBaseObject* update, FDateTime date);

	~UpdateShort();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getupdate() const
	{
		 return this->update;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

private:
	TLBaseObject* update;
	 FDateTime date;
};
} //end namespace block

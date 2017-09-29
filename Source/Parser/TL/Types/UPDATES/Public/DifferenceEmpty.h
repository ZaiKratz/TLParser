#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Updates/Public/Difference.h"

//begin namespace block
namespace UPDATES
{
class DifferenceEmpty : public TLBaseObject
{
public:
	DifferenceEmpty();
	DifferenceEmpty(FDateTime date, int32 seq);

	~DifferenceEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FDateTime Getdate() const
	{
		 return this->date;
	}

	int32 Getseq() const
	{
		 return this->seq;
	}

private:
	FDateTime date;
	 int32 seq;
};
} //end namespace block
